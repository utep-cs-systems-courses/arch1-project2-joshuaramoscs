#ifndef switches_included
#define switches_included

#define SW2 BIT2
#define SW1 BIT3		/* switch1 is p1.3 */
#define SWITCHES (SW1 | SW2)		/* only 1 switch on this board */



#define 

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed; /* effectively boolean */

#endif // included
