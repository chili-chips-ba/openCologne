#include "verilated.h"
#include "Vtb.h"
#include <verilated_fst_c.h>


double sc_time_stamp() { return 0; }

// This is a 64-bit integer to reduce wrap over issues and
// allow modulus.  You can also use a double, if you wish.
/*
ofstream file ("msgpack.bin", ios::out|ios::binary);

double sc_time_stamp () {       // Called by $time in Verilog
  return main_time;           // converts to double, to match
  // what SystemC does
}

void INThandler(int signal)
{
	printf("\nCaught ctrl-c\n");
	done = true;
}

typedef struct {
  uint8_t state;
  char ch;
  uint32_t baud_t;
  vluint64_t last_update;
} uart_context_t;

void uart_init(uart_context_t *context, uint32_t baud_rate) {
  context->baud_t = 1000*1000*1000/baud_rate;
  context->state = 0;
}

void do_uart(uart_context_t *context, bool rx) {
  if (context->state == 0) {
    if (rx)
      context->state++;
  }
  else if (context->state == 1) {
    if (!rx) {
      context->last_update = main_time + context->baud_t/2;
      context->state++;
    }
  }
  else if(context->state == 2) {
    if (main_time > context->last_update) {
      context->last_update += context->baud_t;
      context->ch = 0;
      context->state++;
    }
  }
  else if (context->state < 11) {
    if (main_time > context->last_update) {
      context->last_update += context->baud_t;
      context->ch |= rx << (context->state-3);
      context->state++;
    }
  }
  else {
    if (main_time > context->last_update) {
      context->last_update += context->baud_t;
      file.write (&context->ch, 1);
      putchar(context->ch);
      context->state=1;
    }
  }
}
*/

int main(int argc, char **argv, char **env)
{
  Verilated::debug(0);
  const std::unique_ptr<VerilatedContext> contextp{new VerilatedContext};

  contextp->traceEverOn(true);
  contextp->commandArgs(argc, argv);

  VerilatedFstC *m_trace = new VerilatedFstC;

  const std::unique_ptr<Vtb> topp{new Vtb{contextp.get()}};

  m_trace->set_time_resolution("1ps");
  m_trace->set_time_unit("1ps");
  topp->trace (m_trace, 20);
  m_trace->open("wave.fst");
  

/* 
  uart_context_t uart_context;
  int baud_rate = 0;
  const char *arg = Verilated::commandArgsPlusMatch("uart_baudrate=");
  if (arg[0]) {
    baud_rate = atoi(arg+15);
    if (baud_rate) {
      uart_init(&uart_context, baud_rate);
    }
  } */

  // signal(SIGINT, INThandler);
  long long int t0 = 0;
  while (!contextp->gotFinish()) {
    topp->eval();
    m_trace->dump(contextp->time());

    if (!topp->eventsPending()) break;
    contextp->time(topp->nextTimeSlot());
    t0++;
  }

   if (!contextp->gotFinish()) {
      VL_DEBUG_IF(VL_PRINTF("+ Exiting without $finish; no events left\n"););
   }
  m_trace->close();
  topp->final();
  return 0;
}
