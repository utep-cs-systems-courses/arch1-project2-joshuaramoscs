# LED Files
#### Completed on 3/15/2020

## Description

This interrupt-driven program flashes the LEDs from 0 to 3 as their respective
binary values and makes some buzzing sounds.

## Files Breakdown

### counterMain.c

 * int main();		/* Configures the clock, initializes LEDs, buzzer, buttons, and enables
   interrupts. */

### led.h

 * void led_init();	  /* Initializes the LEDs */
 * void led_update();  	  /* Update the LEDs according to the selections */

### buzzer.h

 * void buzzer_init();	         /* Initializes the buzzer */
 * void buzzer_set_period();	 /* Updates the buzzer according to the cycle
 * selected */

### switches.h

 * void switch_init();			/* Initialize the buttons */
 * void switch_interrupt_handler();	/* Idle for an interruption */

### led_toggle.h

/* *Note: led_toggle.s is written in Assembly Language, but a commented C version can be
found in stateMachines.c */

 * toggle_red();	/* Toggles red led ON if Off, or OFF if ON
 * toggle_green();	/* Toggles green led ON if Off, or OFF if ON

### stateMachines.h

 * char state_zero();  /* Display binary 0 and buzz tone */
 * char state_one();   /* Displays binary 1 and buzz lower tone */
 * char state_two();   /* Displays binary 2 and buzz lower tone */
 * char state_three(); /* Displays binary 3 and buzz lower tone */
 * char state_loop();  /* Loop through state 0 to 3 */

### wdInterruptHandler.c

 * void __interrupt_vec(WDT_VECTOR) WDT(); /* Handles interrupt and starts
   state_loop() instateMachines.h */

###  p2_interrupt_handler.c

 * void __interrupt_vec(PORT2_VECTOR) Port_2(); /* Allows input from P2 */
