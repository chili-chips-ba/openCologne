use alloc::vec::Vec;
use crate::hal_time::get_time_ms;

/// note: the code is structured to use at most 16 rows or 16 cols
const KBD_ROWS: usize = 9;
const KBD_COLS: usize = 10;

/// Keyboard driver HAL.
/// Call update() with a frequency of about once every millisecond, and the subsystem will
/// handle keyscan & debounce automatically. Will report keyup/keydown events. Calling update()
/// more frequently than once a millisecond should have negligble performance impact, as the
/// system will check elapsed time, and if keys have changed before doing an expensive all-matrix 
/// scan operation.


/// get the column activation contents of the given row
/// row is coded as a binary number, so the result of kbd_rowchange has to be decoded from a binary
/// vector of rows to a set of numbers prior to using this function
fn kbd_getrow(p: &betrusted_pac::Peripherals, row: u8) -> u16 {
    match row {
        0 => (p.KEYBOARD.row0dat.read().bits() as u16),
        1 => (p.KEYBOARD.row1dat.read().bits() as u16),
        2 => (p.KEYBOARD.row2dat.read().bits() as u16),
        3 => (p.KEYBOARD.row3dat.read().bits() as u16),
        4 => (p.KEYBOARD.row4dat.read().bits() as u16),
        5 => (p.KEYBOARD.row5dat.read().bits() as u16),
        6 => (p.KEYBOARD.row6dat.read().bits() as u16),
        7 => (p.KEYBOARD.row7dat.read().bits() as u16),
        8 => (p.KEYBOARD.row8dat.read().bits() as u16),
        _ => 0
    }
}

/// scan the entire key matrix and return the list of keys that are currently
/// pressed as key codes. Return format is an option-wrapped vector of u8,
/// which is structured as (row : col), where each of row and col are a u8.
/// Option "none" means no keys were pressed during this scan.
fn kbd_getcodes(p: &betrusted_pac::Peripherals) -> Option<Vec<(usize,usize)>> {
    let mut keys = Vec::new();

    for r in 0..KBD_ROWS {
        let cols: u16 = kbd_getrow(&p, r as u8);
        for c in 0..KBD_COLS {
            if (cols & (1 << c)) != 0 {
                keys.push( (r, c) )
            }
        }
    }

    if keys.len() > 0 {
        Some(keys)
    } else {
        None
    }
}

/// holds the four basic possible values of a key location
pub struct ScanCode {
    /// base key value
    pub key: Option<char>,
    /// tap blue shift key, then key
    pub shift: Option<char>,
    /// hold blue shift key, then key
    pub hold: Option<char>,
    /// hold orange shift key, then key
    pub alt: Option<char>,
}

/// This is the main keyboard manager construct.
pub struct KeyManager {
    /// the peripheral access crate pointer
    p: betrusted_pac::Peripherals,
    /// debounce counter array
    debounce: [[u8; KBD_COLS]; KBD_ROWS],
    /// threshold (in ms) for considering an up or down event to be debounced, in loop interations.
    threshold: u8,
    /// last timestamp (in ms) since last call
    timestamp: u32,
    /// remember the last keycode since a change event
    lastcode: Option<Vec<(usize, usize)>>,
}

impl KeyManager {
    pub fn new() -> Self {
        unsafe{
            KeyManager{
                p: betrusted_pac::Peripherals::steal(),
                debounce: [[0; KBD_COLS]; KBD_ROWS],
                threshold: 5,
                timestamp: get_time_ms(&betrusted_pac::Peripherals::steal()),
                lastcode: None,
            }
        }
    }

    /// returns the current set of codes from the keyboard matrix
    /// note that the hardware returns a signal that indicates if any keys have changed
    /// so when using getcodes() as part of a debounce loop it's recommended to check
    /// the change signal and short-circuit the call if no keys have changed since the
    /// last check. This check is not hard-coded into this call because there are instances
    /// where you want to know the current status of the keys whether or not something
    /// has changed.
    pub fn getcodes(&self) -> Option<Vec<(usize, usize)>> {
        kbd_getcodes(&self.p)
    }

    /// update() is designed to be called at regular intervals (not based on keyboard interrupt)
    /// it will automatically fetch new keycodes if a change event has happened, otherwise
    /// the regular calls to update() are necessary to update the debouncer state
    ///
    /// returns a tuple of (keydown, keyup) scan codes, each of which are an Option-wrapped vector
    pub fn update(&mut self) -> (Option<Vec<(usize, usize)>>, Option<Vec<(usize,usize)>>) {
        let mut downs: [[bool; KBD_COLS]; KBD_ROWS] = [[false; KBD_COLS]; KBD_ROWS];
        let mut keydowns = Vec::new();
        let mut keyups = Vec::new();

        if self.p.KEYBOARD.ev_pending.read().bits() != 0 {
            // only do the getcodes() call if we saw a change to key state
            self.lastcode = kbd_getcodes(&self.p);
            // clear the pending bit
            unsafe{ self.p.KEYBOARD.ev_pending.write(|w| w.bits(1)); }
        }

        let elapsed: u32 = get_time_ms(&self.p) - self.timestamp;
        if (elapsed == 0) && self.lastcode.is_none() {
            // skip debounce processing if time elapsed is too short and there's no key updates
            (None, None)
        } else {
            self.timestamp = get_time_ms(&self.p); // on a "real" pass, update the timestamp accordingly

            // in case a lot of time has elapsed, saturate the debounce increment at the threshold so we don't
            // overflow the debounce counter's u8
            let increment: u8;
            if elapsed > self.threshold as u32 {
                increment = self.threshold;
            } else {
                increment = elapsed as u8;
            }

            // if there's keys pressed, continue to increment the debounce counter
            if self.lastcode.is_some() {
                // this is a little tricky because alloc::Vec doesn't implement a copy operator
                // so we have to take the vector and create a new copy after unwrapping it.betrusted_pac

                let code: Vec<(usize, usize)> = self.lastcode.take().unwrap();
                let mut newcode = Vec::new(); // need to allocate a newcode because alloc::Vec doesn't implement copy
                for key in code {
                    let (row, col) = key;
                    if self.debounce[row][col] < self.threshold {
                        self.debounce[row][col] += increment;
                        // now check if we've passed the debounce threshold, and report a keydown
                        if self.debounce[row][col] >= self.threshold {
                            keydowns.push((row,col));
                        }
                    }
                    downs[row][col] = true;  // record that we processed the key
                    newcode.push((row,col)); // manually copy to a new vect to satisfy lifetime rules
                }
                self.lastcode = Some(newcode);
            }

            // now decrement debounce couter for all elements that don't have a press
            for r in 0..KBD_ROWS {
                for c in 0..KBD_COLS {
                    if !downs[r][c] && (self.debounce[r][c] > 0) {
                        if self.debounce[r][c] >= increment {
                            self.debounce[r][c] -= increment;
                        } else {
                            self.debounce[r][c] = 0;
                        }

                        if self.debounce[r][c] == 0 {
                            keyups.push((r, c));
                        }
                    }
               }
            }

            // formulate the keyup/keydown return values
            let retdowns: Option<Vec<(usize, usize)>>;
            if keydowns.len() > 0 {
                retdowns = Some(keydowns);
            } else {
                retdowns = None;
            }
            let retups: Option<Vec<(usize, usize)>>;
            if keyups.len() > 0 {
                retups = Some(keyups);
            } else {
                retups = None;
            }

            (retdowns, retups)
        }
    }
}

    /// Compute the dvorak key mapping of row/col to key tuples
    pub fn map_dvorak(code: (usize,usize)) -> ScanCode {
        if cfg!(feature = "evt") {
            match code {
                (0, 0) => ScanCode{key: Some('1'), shift: Some('1'), hold: None, alt: None},
                (0, 1) => ScanCode{key: Some('2'), shift: Some('2'), hold: None, alt: None},
                (0, 2) => ScanCode{key: Some('3'), shift: Some('3'), hold: None, alt: None},
                (0, 3) => ScanCode{key: Some('4'), shift: Some('4'), hold: None, alt: None},
                (0, 4) => ScanCode{key: Some('5'), shift: Some('5'), hold: None, alt: None},
                (4, 5) => ScanCode{key: Some('6'), shift: Some('6'), hold: None, alt: None},
                (4, 6) => ScanCode{key: Some('7'), shift: Some('7'), hold: None, alt: None},
                (4, 7) => ScanCode{key: Some('8'), shift: Some('8'), hold: None, alt: None},
                (4, 8) => ScanCode{key: Some('9'), shift: Some('9'), hold: None, alt: None},
                (4, 9) => ScanCode{key: Some('0'), shift: Some('0'), hold: None, alt: None},

                (1, 0) => ScanCode{key: Some(0x8_u8.into()), shift: Some(0x8_u8.into()), hold: Some(0x8_u8.into()), alt: Some(0x8_u8.into())}, // backspace
                (1, 1) => ScanCode{key: Some('\''), shift: Some('\''), hold: Some('@'), alt: None},
                (1, 2) => ScanCode{key: Some('p'), shift: Some('P'), hold: Some('#'), alt: None},
                (1, 3) => ScanCode{key: Some('y'), shift: Some('Y'), hold: Some('&'), alt: None},
                (1, 4) => ScanCode{key: Some('f'), shift: Some('F'), hold: Some('*'), alt: None},
                (5, 5) => ScanCode{key: Some('g'), shift: Some('G'), hold: Some('-'), alt: None},
                (5, 6) => ScanCode{key: Some('c'), shift: Some('C'), hold: Some('+'), alt: None},
                (5, 7) => ScanCode{key: Some('r'), shift: Some('R'), hold: Some('('), alt: None},
                (5, 8) => ScanCode{key: Some('l'), shift: Some('L'), hold: Some(')'), alt: None},
                (5, 9) => ScanCode{key: Some('?'), shift: Some('?'), hold: Some('!'), alt: None},

                (2, 0) => ScanCode{key: Some('a'), shift: Some('A'), hold: Some('\\'), alt: None},
                (2, 1) => ScanCode{key: Some('o'), shift: Some('O'), hold: Some('`'), alt: None},
                (2, 2) => ScanCode{key: Some('e'), shift: Some('E'), hold: Some('~'), alt: None},
                (2, 3) => ScanCode{key: Some('u'), shift: Some('U'), hold: Some('|'), alt: None},
                (2, 4) => ScanCode{key: Some('i'), shift: Some('I'), hold: Some('['), alt: None},
                (6, 5) => ScanCode{key: Some('d'), shift: Some('D'), hold: Some(']'), alt: None},
                (6, 6) => ScanCode{key: Some('h'), shift: Some('H'), hold: Some('<'), alt: None},
                (6, 7) => ScanCode{key: Some('t'), shift: Some('T'), hold: Some('>'), alt: None},
                (6, 8) => ScanCode{key: Some('n'), shift: Some('N'), hold: Some('{'), alt: None},
                (6, 9) => ScanCode{key: Some('s'), shift: Some('S'), hold: Some('}'), alt: None},

                (3, 0) => ScanCode{key: Some('q'), shift: Some('Q'), hold: Some('_'), alt: None}, // aliased for power-on
                (3, 1) => ScanCode{key: Some('j'), shift: Some('J'), hold: Some('$'), alt: None},
                (3, 2) => ScanCode{key: Some('k'), shift: Some('K'), hold: Some('"'), alt: None},
                (3, 3) => ScanCode{key: Some('x'), shift: Some('X'), hold: Some(':'), alt: None},
                (3, 4) => ScanCode{key: Some('b'), shift: Some('B'), hold: Some(';'), alt: None},
                (7, 5) => ScanCode{key: Some('m'), shift: Some('M'), hold: Some('/'), alt: None},
                (7, 6) => ScanCode{key: Some('w'), shift: Some('W'), hold: Some('^'), alt: None},
                (7, 7) => ScanCode{key: Some('v'), shift: Some('V'), hold: Some('='), alt: None},
                (7, 8) => ScanCode{key: Some('z'), shift: Some('Z'), hold: Some('%'), alt: None},
                (7, 9) => ScanCode{key: Some(0xd_u8.into()), shift: Some(0xd_u8.into()), hold: Some(0xd_u8.into()), alt: Some(0xd_u8.into())}, // carriage return

                (8, 5) => ScanCode{key: Some(0xf_u8.into()), shift: Some(0xf_u8.into()), hold: Some(0xf_u8.into()), alt: Some(0xf_u8.into())}, // shift in (blue shift)
                (8, 6) => ScanCode{key: Some(','), shift: Some(0xe_u8.into()), hold: Some(0xe_u8.into()), alt: None},  // 0xe is shift out (sym)
                (8, 7) => ScanCode{key: Some(' '), shift: Some(' '), hold: Some(' '), alt: None},
                (8, 8) => ScanCode{key: Some('.'), shift: Some('😃'), hold: Some('😃'), alt: None},
                // aliased for power-on
                (8, 9) => ScanCode{key: Some(0xf_u8.into()), shift: Some(0xf_u8.into()), hold: Some(0xf_u8.into()), alt: Some(0xf_u8.into())}, // shift in (blue shift)

                // these are all bugged: row values are swapped on PCB
                // the F0/tab key also doubles as a secondary power key (can't do UP5K UART rx at same time)
                (8, 0) => ScanCode{key: Some(0x11_u8.into()), shift: Some(0x11_u8.into()), hold: Some(0x11_u8.into()), alt: Some(0x11_u8.into())}, // DC1 (F1)
                (8, 1) => ScanCode{key: Some(0x12_u8.into()), shift: Some(0x12_u8.into()), hold: Some(0x12_u8.into()), alt: Some(0x12_u8.into())}, // DC2 (F2)
                (3, 8) => ScanCode{key: Some(0x13_u8.into()), shift: Some(0x13_u8.into()), hold: Some(0x13_u8.into()), alt: Some(0x13_u8.into())}, // DC3 (F3)
                // the F4/ctrl key also doubles as a power key
                (3, 9) => ScanCode{key: Some(0x14_u8.into()), shift: Some(0x14_u8.into()), hold: Some(0x14_u8.into()), alt: Some(0x14_u8.into())}, // DC4 (F4)
                (8, 3) => ScanCode{key: Some('←'), shift: Some('←'), hold: Some('←'), alt: Some('←')},
                (3, 6) => ScanCode{key: Some('→'), shift: Some('→'), hold: Some('→'), alt: Some('→')},
                (6, 4) => ScanCode{key: Some('↑'), shift: Some('↑'), hold: Some('↑'), alt: Some('↑')},
                (8, 2) => ScanCode{key: Some('↓'), shift: Some('↓'), hold: Some('↓'), alt: Some('↓')},
                // this one is OK
                (5, 2) => ScanCode{key: Some('∴'), shift: Some('∴'), hold: Some('∴'), alt: Some('∴')},

                _ => ScanCode {key: None, shift: None, hold: None, alt: None}
            }
        } else if cfg!(feature = "dvt") {
            match code {
                (0, 0) => ScanCode{key: Some('1'), shift: Some('1'), hold: None, alt: None},
                (0, 1) => ScanCode{key: Some('2'), shift: Some('2'), hold: None, alt: None},
                (0, 2) => ScanCode{key: Some('3'), shift: Some('3'), hold: None, alt: None},
                (0, 3) => ScanCode{key: Some('4'), shift: Some('4'), hold: None, alt: None},
                (0, 4) => ScanCode{key: Some('5'), shift: Some('5'), hold: None, alt: None},
                (4, 5) => ScanCode{key: Some('6'), shift: Some('6'), hold: None, alt: None},
                (4, 6) => ScanCode{key: Some('7'), shift: Some('7'), hold: None, alt: None},
                (4, 7) => ScanCode{key: Some('8'), shift: Some('8'), hold: None, alt: None},
                (4, 8) => ScanCode{key: Some('9'), shift: Some('9'), hold: None, alt: None},
                (4, 9) => ScanCode{key: Some('0'), shift: Some('0'), hold: None, alt: None},

                (1, 0) => ScanCode{key: Some(0x8_u8.into()), shift: Some(0x8_u8.into()), hold: Some(0x8_u8.into()), alt: Some(0x8_u8.into())}, // backspace
                (1, 1) => ScanCode{key: Some('\''), shift: Some('\''), hold: Some('@'), alt: None},
                (1, 2) => ScanCode{key: Some('p'), shift: Some('P'), hold: Some('#'), alt: None},
                (1, 3) => ScanCode{key: Some('y'), shift: Some('Y'), hold: Some('&'), alt: None},
                (1, 4) => ScanCode{key: Some('f'), shift: Some('F'), hold: Some('*'), alt: None},
                (5, 5) => ScanCode{key: Some('g'), shift: Some('G'), hold: Some('-'), alt: None},
                (5, 6) => ScanCode{key: Some('c'), shift: Some('C'), hold: Some('+'), alt: None},
                (5, 7) => ScanCode{key: Some('r'), shift: Some('R'), hold: Some('('), alt: None},
                (5, 8) => ScanCode{key: Some('l'), shift: Some('L'), hold: Some(')'), alt: None},
                (5, 9) => ScanCode{key: Some('?'), shift: Some('?'), hold: Some('!'), alt: None},

                (2, 0) => ScanCode{key: Some('a'), shift: Some('A'), hold: Some('\\'), alt: None},
                (2, 1) => ScanCode{key: Some('o'), shift: Some('O'), hold: Some('`'), alt: None},
                (2, 2) => ScanCode{key: Some('e'), shift: Some('E'), hold: Some('~'), alt: None},
                (2, 3) => ScanCode{key: Some('u'), shift: Some('U'), hold: Some('|'), alt: None},
                (2, 4) => ScanCode{key: Some('i'), shift: Some('I'), hold: Some('['), alt: None},
                (6, 5) => ScanCode{key: Some('d'), shift: Some('D'), hold: Some(']'), alt: None},
                (6, 6) => ScanCode{key: Some('h'), shift: Some('H'), hold: Some('<'), alt: None},
                (6, 7) => ScanCode{key: Some('t'), shift: Some('T'), hold: Some('>'), alt: None},
                (6, 8) => ScanCode{key: Some('n'), shift: Some('N'), hold: Some('{'), alt: None},
                (6, 9) => ScanCode{key: Some('s'), shift: Some('S'), hold: Some('}'), alt: None},

                (3, 0) => ScanCode{key: Some('q'), shift: Some('Q'), hold: Some('_'), alt: None},
                (3, 1) => ScanCode{key: Some('j'), shift: Some('J'), hold: Some('$'), alt: None},
                (3, 2) => ScanCode{key: Some('k'), shift: Some('K'), hold: Some('"'), alt: None},
                (3, 3) => ScanCode{key: Some('x'), shift: Some('X'), hold: Some(':'), alt: None},
                (3, 4) => ScanCode{key: Some('b'), shift: Some('B'), hold: Some(';'), alt: None},
                (7, 5) => ScanCode{key: Some('m'), shift: Some('M'), hold: Some('/'), alt: None},
                (7, 6) => ScanCode{key: Some('w'), shift: Some('W'), hold: Some('^'), alt: None},
                (7, 7) => ScanCode{key: Some('v'), shift: Some('V'), hold: Some('='), alt: None},
                (7, 8) => ScanCode{key: Some('z'), shift: Some('Z'), hold: Some('%'), alt: None},
                (7, 9) => ScanCode{key: Some(0xd_u8.into()), shift: Some(0xd_u8.into()), hold: Some(0xd_u8.into()), alt: Some(0xd_u8.into())}, // carriage return

                (8, 5) => ScanCode{key: Some(0xf_u8.into()), shift: Some(0xf_u8.into()), hold: Some(0xf_u8.into()), alt: Some(0xf_u8.into())}, // shift in (blue shift)
                (8, 6) => ScanCode{key: Some(','), shift: Some(0xe_u8.into()), hold: Some(0xe_u8.into()), alt: None},  // 0xe is shift out (sym)
                (8, 7) => ScanCode{key: Some(' '), shift: Some(' '), hold: Some(' '), alt: None},
                (8, 8) => ScanCode{key: Some('.'), shift: Some('😃'), hold: Some('😃'), alt: None},
                (8, 9) => ScanCode{key: Some(0xf_u8.into()), shift: Some(0xf_u8.into()), hold: Some(0xf_u8.into()), alt: Some(0xf_u8.into())}, // shift in (blue shift)

                // these are all bugged: row values are swapped on PCB
                // the F0/tab key also doubles as a secondary power key (can't do UP5K UART rx at same time)
                (4, 0) => ScanCode{key: Some(0x11_u8.into()), shift: Some(0x11_u8.into()), hold: Some(0x11_u8.into()), alt: Some(0x11_u8.into())}, // DC1 (F1)
                (4, 1) => ScanCode{key: Some(0x12_u8.into()), shift: Some(0x12_u8.into()), hold: Some(0x12_u8.into()), alt: Some(0x12_u8.into())}, // DC2 (F2)
                (3, 8) => ScanCode{key: Some(0x13_u8.into()), shift: Some(0x13_u8.into()), hold: Some(0x13_u8.into()), alt: Some(0x13_u8.into())}, // DC3 (F3)
                // the F4/ctrl key also doubles as a power key
                (3, 9) => ScanCode{key: Some(0x14_u8.into()), shift: Some(0x14_u8.into()), hold: Some(0x14_u8.into()), alt: Some(0x14_u8.into())}, // DC4 (F4)
                (4, 3) => ScanCode{key: Some('←'), shift: Some('←'), hold: Some('←'), alt: Some('←')},
                (3, 6) => ScanCode{key: Some('→'), shift: Some('→'), hold: Some('→'), alt: Some('→')},
                (6, 4) => ScanCode{key: Some('↑'), shift: Some('↑'), hold: Some('↑'), alt: Some('↑')},
                (8, 2) => ScanCode{key: Some('↓'), shift: Some('↓'), hold: Some('↓'), alt: Some('↓')},
                // this one is OK
                (5, 2) => ScanCode{key: Some('∴'), shift: Some('∴'), hold: Some('∴'), alt: Some('∴')},

                _ => ScanCode {key: None, shift: None, hold: None, alt: None}
            }
        } else {
            assert!(false);  // should never get here
            ScanCode {key: None, shift: None, hold: None, alt: None}
        }
    }


    /// Compute the dvorak key mapping of row/col to key tuples
    pub fn map_qwerty(code: (usize,usize)) -> ScanCode {
        match code {
            (0, 0) => ScanCode{key: Some('1'), shift: Some('1'), hold: None, alt: None},
            (0, 1) => ScanCode{key: Some('2'), shift: Some('2'), hold: None, alt: None},
            (0, 2) => ScanCode{key: Some('3'), shift: Some('3'), hold: None, alt: None},
            (0, 3) => ScanCode{key: Some('4'), shift: Some('4'), hold: None, alt: None},
            (0, 4) => ScanCode{key: Some('5'), shift: Some('5'), hold: None, alt: None},
            (4, 5) => ScanCode{key: Some('6'), shift: Some('6'), hold: None, alt: None},
            (4, 6) => ScanCode{key: Some('7'), shift: Some('7'), hold: None, alt: None},
            (4, 7) => ScanCode{key: Some('8'), shift: Some('8'), hold: None, alt: None},
            (4, 8) => ScanCode{key: Some('9'), shift: Some('9'), hold: None, alt: None},
            (4, 9) => ScanCode{key: Some('0'), shift: Some('0'), hold: None, alt: None},

            (1, 0) => ScanCode{key: Some('q'), shift: Some('Q'), hold: Some('%'), alt: None}, // backspace
            (1, 1) => ScanCode{key: Some('w'), shift: Some('W'), hold: Some('^'), alt: None},
            (1, 2) => ScanCode{key: Some('e'), shift: Some('E'), hold: Some('~'), alt: None},
            (1, 3) => ScanCode{key: Some('r'), shift: Some('R'), hold: Some('|'), alt: None},
            (1, 4) => ScanCode{key: Some('t'), shift: Some('T'), hold: Some('['), alt: None},
            (5, 5) => ScanCode{key: Some('y'), shift: Some('Y'), hold: Some(']'), alt: None},
            (5, 6) => ScanCode{key: Some('u'), shift: Some('U'), hold: Some('<'), alt: None},
            (5, 7) => ScanCode{key: Some('i'), shift: Some('I'), hold: Some('>'), alt: None},
            (5, 8) => ScanCode{key: Some('o'), shift: Some('O'), hold: Some('{'), alt: None},
            (5, 9) => ScanCode{key: Some('p'), shift: Some('P'), hold: Some('}'), alt: None},

            (2, 0) => ScanCode{key: Some('a'), shift: Some('A'), hold: Some('@'), alt: None},
            (2, 1) => ScanCode{key: Some('s'), shift: Some('S'), hold: Some('#'), alt: None},
            (2, 2) => ScanCode{key: Some('d'), shift: Some('D'), hold: Some('&'), alt: None},
            (2, 3) => ScanCode{key: Some('f'), shift: Some('F'), hold: Some('*'), alt: None},
            (2, 4) => ScanCode{key: Some('g'), shift: Some('G'), hold: Some('-'), alt: None},
            (6, 5) => ScanCode{key: Some('h'), shift: Some('H'), hold: Some('+'), alt: None},
            (6, 6) => ScanCode{key: Some('j'), shift: Some('J'), hold: Some('='), alt: None},
            (6, 7) => ScanCode{key: Some('k'), shift: Some('K'), hold: Some('('), alt: None},
            (6, 8) => ScanCode{key: Some('l'), shift: Some('L'), hold: Some(')'), alt: None},
            (6, 9) => ScanCode{key: Some(0x8_u8.into()), shift: Some(0x8_u8.into()), hold: Some(0x8_u8.into()), alt: Some(0x8_u8.into())},

            (3, 0) => ScanCode{key: Some('!'), shift: Some('!'), hold: Some('`'), alt: None},
            (3, 1) => ScanCode{key: Some('z'), shift: Some('Z'), hold: Some('_'), alt: None},
            (3, 2) => ScanCode{key: Some('x'), shift: Some('X'), hold: Some('$'), alt: None},
            (3, 3) => ScanCode{key: Some('c'), shift: Some('C'), hold: Some('"'), alt: None},
            (3, 4) => ScanCode{key: Some('v'), shift: Some('V'), hold: Some('\''), alt: None},
            (7, 5) => ScanCode{key: Some('b'), shift: Some('B'), hold: Some(':'), alt: None},
            (7, 6) => ScanCode{key: Some('n'), shift: Some('N'), hold: Some(';'), alt: None},
            (7, 7) => ScanCode{key: Some('m'), shift: Some('M'), hold: Some('/'), alt: None},
            (7, 8) => ScanCode{key: Some('?'), shift: Some('?'), hold: Some('\\'), alt: None},
            (7, 9) => ScanCode{key: Some(0xd_u8.into()), shift: Some(0xd_u8.into()), hold: Some(0xd_u8.into()), alt: Some(0xd_u8.into())}, // carriage return

            (8, 5) => ScanCode{key: Some(0xf_u8.into()), shift: Some(0xf_u8.into()), hold: Some(0xf_u8.into()), alt: Some(0xf_u8.into())}, // shift in (blue shift)
            (8, 6) => ScanCode{key: Some(','), shift: Some(0xe_u8.into()), hold: Some(0xe_u8.into()), alt: None},  // 0xe is shift out (sym)
            (8, 7) => ScanCode{key: Some(' '), shift: Some(' '), hold: Some(' '), alt: None},
            (8, 8) => ScanCode{key: Some('.'), shift: Some('😃'), hold: Some('😃'), alt: None},
            (8, 9) => ScanCode{key: Some(0xf_u8.into()), shift: Some(0xf_u8.into()), hold: Some(0xf_u8.into()), alt: Some(0xf_u8.into())}, // shift in (blue shift)

            // the F0/tab key also doubles as a secondary power key (can't do UP5K UART rx at same time)
            (4, 0) => ScanCode{key: Some(0x11_u8.into()), shift: Some(0x11_u8.into()), hold: Some(0x11_u8.into()), alt: Some(0x11_u8.into())}, // DC1 (F1)
            (4, 1) => ScanCode{key: Some(0x12_u8.into()), shift: Some(0x12_u8.into()), hold: Some(0x12_u8.into()), alt: Some(0x12_u8.into())}, // DC2 (F2)
            (3, 8) => ScanCode{key: Some(0x13_u8.into()), shift: Some(0x13_u8.into()), hold: Some(0x13_u8.into()), alt: Some(0x13_u8.into())}, // DC3 (F3)
            // the F4/ctrl key also doubles as a power key
            (3, 9) => ScanCode{key: Some(0x14_u8.into()), shift: Some(0x14_u8.into()), hold: Some(0x14_u8.into()), alt: Some(0x14_u8.into())}, // DC4 (F4)
            (4, 3) => ScanCode{key: Some('←'), shift: Some('←'), hold: Some('←'), alt: Some('←')},
            (3, 6) => ScanCode{key: Some('→'), shift: Some('→'), hold: Some('→'), alt: Some('→')},
            (6, 4) => ScanCode{key: Some('↑'), shift: Some('↑'), hold: Some('↑'), alt: Some('↑')},
            (8, 2) => ScanCode{key: Some('↓'), shift: Some('↓'), hold: Some('↓'), alt: Some('↓')},
            // this one is OK
            (5, 2) => ScanCode{key: Some('∴'), shift: Some('∴'), hold: Some('∴'), alt: Some('∴')},

            _ => ScanCode {key: None, shift: None, hold: None, alt: None}
        }
    }