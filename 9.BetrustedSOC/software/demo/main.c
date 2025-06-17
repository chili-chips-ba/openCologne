#include <generated/csr.h>
#include <generated/soc.h>

void isr(void) {
    // No interrupts used
}

int main() {
   while(1){
    while (uart_txfull_read());      // Wait until TX FIFO not full
    uart_rxtx_write('A');            // Send char
   }
   return 0;
}
