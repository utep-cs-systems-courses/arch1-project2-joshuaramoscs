#include <msp430.h>
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count == 125) { //125
    switch_interrupt_handler();
    blink_count = 0;
  }
}
