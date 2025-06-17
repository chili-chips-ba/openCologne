//! A heap allocator for RiscV processors
//! Derived from cortex-m heap allocator

#![feature(allocator_api)]
//#![feature(const_fn)]
#![no_std]

extern crate alloc;
extern crate riscv;
extern crate linked_list_allocator;
extern crate spin;

use core::alloc::{GlobalAlloc, Layout};
use core::ptr::NonNull;

use spin::Mutex;

use linked_list_allocator::Heap;

pub struct RiscvHeap {
    heap: Mutex<Heap>,
}

impl RiscvHeap {
    /// Crate a new UNINITIALIZED heap allocator
    ///
    /// You must initialize this heap using the
    /// [`init`](struct.RiscvHeap.html#method.init) method before using the allocator.
    pub const fn empty() -> RiscvHeap {
        RiscvHeap {
            heap: Mutex::new(Heap::empty()),
        }
    }

    /// Initializes the heap
    ///
    /// This function must be called BEFORE you run any code that makes use of the
    /// allocator.
    ///
    /// `start_addr` is the address where the heap will be located.
    ///
    /// `size` is the size of the heap in bytes.
    ///
    /// Note that:
    ///
    /// - The heap grows "upwards", towards larger addresses. Thus `end_addr` must
    ///   be larger than `start_addr`
    ///
    /// - The size of the heap is `(end_addr as usize) - (start_addr as usize)`. The
    ///   allocator won't use the byte at `end_addr`.
    ///
    /// # Unsafety
    ///
    /// Obey these or Bad Stuff will happen.
    ///
    /// - This function must be called exactly ONCE.
    /// - `size > 0`
    pub unsafe fn init(&self, start_addr: usize, size: usize) {
        self.heap.lock()
        .init(start_addr, size);
    }
}

unsafe impl GlobalAlloc for RiscvHeap {
    unsafe fn alloc(&self, layout: Layout) -> *mut u8 {
        self.heap
        .lock()
        .allocate_first_fit(layout)
        .ok()
        .map_or(0 as *mut u8, |allocation| allocation.as_ptr())
    }

    unsafe fn dealloc(&self, ptr: *mut u8, layout: Layout) {
        self.heap
        .lock()
        .deallocate(NonNull::new_unchecked(ptr), layout)
    }
}
