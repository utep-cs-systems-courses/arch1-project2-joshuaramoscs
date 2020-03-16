/* Cycle binary values 0 to 3 with LEDs */
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

/* Configures the clock, initializes LEDs, and enables interrupts. */
int main(void) {
  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  led_init();
  enableWDTInterrupts();	/* enable periodic interrupt */

  or_sr(0x18);		/* CPU off, GIE on */
}
