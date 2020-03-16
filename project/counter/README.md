# LED Files
#### Completed on 3/15/2020

## Description

This interrupt-driven program flashes the LEDs from 0 to 3 as their respective
binary values.

## Files Breakdown

### ledMain.c

 * int main(); /* Configures the clock, initializes LEDs, and enables
   interrupts. */

### led.h

 * void led_init();    /* Initializes the LEDs */
 * void led_update();  /* Update the LEDs according to the selections */

### stateMachines.h

 * char state_zero();  /* Display binary 0 */
 * char state_one();   /* Displays binary 1 */
 * char state_two();   /* Displays binary 2 */
 * char state_three(); /* Displays binary 3 */
 * char state_loop();  /* Loop through state 0 to 3 */

### wdInterruptHandler.c

 * void __interrupt_vec(WDT_VECTOR) WDT(); /* Handles interrupt and starts
   state_loop() instateMachines.h */
