use core::num::NonZeroUsize;

#[allow(dead_code)] pub type MemoryAddress = NonZeroUsize;
#[allow(dead_code)] pub type MemorySize = NonZeroUsize;
#[allow(dead_code)] pub type StackPointer = usize;
#[allow(dead_code)] pub type MessageId = usize;

#[allow(dead_code)] pub type XousPid = u8;
#[allow(dead_code)] pub type XousMessageSender = usize;
#[allow(dead_code)] pub type XousConnection = usize;

/// Server ID
#[allow(dead_code)] pub type XousSid = usize;

/// Equivalent to a RISC-V Hart ID
#[allow(dead_code)] pub type XousCpuId = usize;

#[allow(dead_code)]
#[derive(Debug)]
pub enum XousError {
    BadAlignment,
    BadAddress,
    OutOfMemory,
    MemoryInUse,
    InterruptNotFound,
    InterruptInUse,
    InvalidString,
    ServerExists,
    ServerNotFound,
    ProcessNotFound,
    ProcessNotChild,
    ProcessTerminated,
    Timeout,
}

#[allow(dead_code)]
pub struct XousContext {
    stack: StackPointer,
    pid: XousPid,
}

#[allow(dead_code)]
pub struct XousMemoryMessage {
    id: MessageId,
    in_buf: Option<MemoryAddress>,
    in_buf_size: Option<MemorySize>,
    out_buf: Option<MemoryAddress>,
    out_buf_size: Option<MemorySize>,
}

#[allow(dead_code)]
pub struct XousScalarMessage {
    id: MessageId,
    arg1: usize,
    arg2: usize,
    arg3: usize,
    arg4: usize,
}

#[allow(dead_code)]
pub enum XousMessage {
    Memory(XousMemoryMessage),
    Scalar(XousScalarMessage),
}

#[allow(dead_code)]
pub struct XousMessageReceived {
    sender: XousMessageSender,
    message: XousMessage,
}
