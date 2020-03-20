#ifndef stateMachine_included
#define stateMachine_included

char state_zero();  /* Display binary 0 and buzz tone */
char state_one();   /* Display binary 1 and buzz lower tone */
char state_two();   /* Display binary 2 and buzz lower tone */
char state_three(); /* Display binary 3 and buzz lower tone */
void state_loop();  /* Loop through state 0 to 3 */

#endif // included
