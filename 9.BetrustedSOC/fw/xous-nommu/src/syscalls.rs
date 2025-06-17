use super::definitions::*;

/// Claims an interrupt and unmasks it immediately.  The provided function will
/// be called from within an interrupt context, but using the ordinary privilege level of
/// the process.
///
/// # Errors
///
/// * **InterruptNotFound**: The specified interrupt isn't valid on this system
/// * **InterruptInUse**: The specified interrupt has already been claimed
pub fn sys_interrupt_claim(irq: usize, f: fn(usize)) -> Result<(), XousError> {
    crate::irq::sys_interrupt_claim(irq, f)
}

extern "Rust" {
    /// Allocates kernel structures for a new process, and returns the new PID.
    /// This removes `page_count` page tables from the calling process at `origin_address`
    /// and places them at `target_address`.
    ///
    /// If the process was created successfully, then the new PID is returned to
    /// the calling process.  The child is not automatically scheduled for running.
    ///
    /// # Errors
    ///
    /// * **BadAlignment**: `origin_address` or `target_address` were not page-aligned,
    ///                   or `address_size` was not a multiple of the page address size.
    /// * **OutOfMemory**: The kernel couldn't allocate memory for the new process.
    #[allow(dead_code)]
    pub fn sys_process_spawn(
        origin_address: MemoryAddress,
        target_address: MemoryAddress,
        address_size: MemorySize,
    ) -> Result<XousPid, XousError>;

    /// Pauses execution of the current thread and returns execution to the parent
    /// process.  This function may return at any time in the future, including immediately.
    #[allow(dead_code)]
    pub fn sys_process_yield();

    /// Interrupts the current process and returns control to the parent process.
    ///
    /// # Errors
    ///
    /// * **ProcessNotFound**: The provided PID doesn't exist, or is not running on the given CPU.
    #[allow(dead_code)]
    pub fn sysi_process_suspend(pid: XousPid, cpu_id: XousCpuId) -> Result<(), XousError>;

    /// Returns the interrupt back to the operating system and masks it again.
    /// This function is implicitly called when a process exits.
    /// 
    /// # Errors
    /// 
    /// * **InterruptNotFound**: The specified interrupt doesn't exist, or isn't assigned
    ///                          to this process.
    #[allow(dead_code)]
    pub fn sys_interrupt_free(irq: usize) -> Result<(), XousError>;

    /// Resumes a process using the given stack pointer.  A parent could use
    /// this function to implement multi-threading inside a child process, or
    /// to create a task switcher.
    ///
    /// To resume a process exactly where it left off, set `stack_pointer` to `None`.
    /// This would be done in a very simple system that has no threads.
    ///
    /// By default, at most three context switches can be made before the quantum
    /// expires.  To enable more, pass `additional_contexts`.
    ///
    /// If no more contexts are available when one is required, then the child
    /// automatically relinquishes its quantum.
    ///
    /// # Returns
    ///
    /// When this function returns, it provides a list of the processes and
    /// stack pointers that are ready to be run.  Three can fit as return values,
    /// and additional context switches will be supplied in the slice of context
    /// switches, if one is provided.
    ///
    /// # Examples
    ///
    /// If a process called `yield()`, or if its quantum expired normally, then
    /// a single context is returned: The target thread, and its stack pointer.
    ///
    /// If the child process called `client_send()` and ended up blocking due to
    /// the server not being ready, then this would return no context switches.
    /// This thread or process should not be scheduled to run.
    ///
    /// If the child called `client_send()` and the server was ready, then the
    /// server process would be run immediately.  If the child process' quantum
    /// expired while the server was running, then this function would return
    /// a single context containing the PID of the server, and the stack pointer.
    ///
    /// If the child called `client_send()` and the server was ready, then the
    /// server process would be run immediately.  If the server then finishes,
    /// execution flow is returned to the child process.  If the quantum then
    /// expires, this would return two contexts: the server's PID and its stack
    /// pointer when it called `client_reply()`, and the child's PID with its
    /// current stack pointer.
    ///
    /// If the server in turn called another server, and both servers ended up
    /// returning to the child before the quantum expired, then there would be
    /// three contexts on the stack.
    ///
    /// # Errors
    ///
    /// * **ProcessNotFound**: The requested process does not exist
    /// * **ProcessNotChild**: The given process was not a child process, and
    ///                        therefore couldn't be resumed.
    /// * **ProcessTerminated**: The process has crashed.
    #[allow(dead_code)]
    pub fn sys_process_resume(
        process_id: XousPid,
        stack_pointer: Option<usize>,
        additional_contexts: &Option<&[XousContext]>,
    ) -> Result<
        (
            Option<XousContext>,
            Option<XousContext>,
            Option<XousContext>,
        ),
        XousError,
    >;

    /// Causes a process to terminate immediately.
    ///
    /// It is recommended that this function only be called on processes that
    /// have cleaned up after themselves, e.g. shut down any servers and
    /// flushed any file descriptors.
    ///
    /// # Errors
    ///
    /// * **ProcessNotFound**: The requested process does not exist
    /// * **ProcessNotChild**: The requested process is not our child process
    #[allow(dead_code)]
    pub fn sys_process_terminate(process_id: XousPid) -> Result<(), XousError>;

    /// Allocates pages of memory, equal to a total of `size
    /// bytes.  If a physical address is specified, then this
    /// can be used to allocate regions such as memory-mapped I/O.
    /// If a virtual address is specified, then the returned
    /// pages are located at that address.  Otherwise, they
    /// are located at an unspecified offset.
    ///
    /// # Errors
    ///
    /// * **BadAlignment**: Either the physical or virtual addresses aren't page-aligned, or the size isn't a multiple of the page width.
    /// * **OutOfMemory**: A contiguous chunk of memory couldn't be found, or the system's memory size has been exceeded.
    #[allow(dead_code)]
    pub fn sys_memory_allocate(
        phys: Option<MemoryAddress>,
        virt: Option<MemoryAddress>,
        size: MemorySize,
    ) -> Result<MemoryAddress, XousError>;

    /// Equivalent to the Unix `sbrk` call.  Adjusts the
    /// heap size to be equal to the specified value.  Heap
    /// sizes start out at 0 bytes in new processes.
    ///
    /// # Errors
    ///
    /// * **OutOfMemory**: The region couldn't be extended.
    #[allow(dead_code)]
    pub fn sys_heap_resize(size: MemorySize) -> Result<(), XousError>;

    ///! Message Passing Functions

    /// Create a new server with the given name.  This enables other processes to
    /// connect to this server to send messages.  Only one server name may exist
    /// on a system at a time.
    ///
    /// # Errors
    ///
    /// * **ServerExists**: A server has already registered with that name
    /// * **InvalidString**: The name was not a valid UTF-8 string
    #[allow(dead_code)]
    pub fn sys_server_create(server_name: usize) -> Result<XousSid, XousError>;

    /// Suspend the current process until a message is received.  This thread will
    /// block until a message is received.
    ///
    /// # Errors
    ///
    #[allow(dead_code)]
    pub fn sys_server_receive(server_id: XousSid) -> Result<XousMessageReceived, XousError>;

    /// Reply to a message received.  The thread will be unblocked, and will be
    /// scheduled to run sometime in the future.
    ///
    /// If the message that we're responding to is a Memory message, then it should be
    /// passed back directly to the destination without modification -- the actual contents
    /// will be passed in the `out` address pointed to by the structure.
    ///
    /// # Errors
    ///
    /// * **ProcessTerminated**: The process we're replying to doesn't exist any more.
    /// * **BadAddress**: The message didn't pass back all the memory it should have.
    #[allow(dead_code)]
    pub fn sys_server_reply(
        destination: XousMessageSender,
        message: XousMessage,
    ) -> Result<(), XousError>;

    /// Look up a server name and connect to it.
    ///
    /// # Errors
    ///
    /// * **ServerNotFound**: No server is registered with that name.
    #[allow(dead_code)]
    pub fn sys_client_connect(server_name: usize) -> Result<XousConnection, XousError>;

    /// Send a message to a server.  This thread will block until the message is responded to.
    /// If the message type is `Memory`, then the memory addresses pointed to will be
    /// unavailable to this process until this function returns.
    ///
    /// # Errors
    ///
    /// * **ServerNotFound**: The server does not exist so the connection is now invalid
    /// * **BadAddress**: The client tried to pass a Memory message using an address it doesn't own
    /// * **Timeout**: The timeout limit has been reached
    #[allow(dead_code)]
    pub fn sys_client_send(
        server: XousConnection,
        message: XousMessage,
    ) -> Result<XousMessage, XousError>;
}
