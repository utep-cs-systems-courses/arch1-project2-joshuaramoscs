#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

/* LED RED/GREEN toggle section */

char toggle_red()            /* Toggles red led ON if OFF, or OFF if ON. */
{
  char changed = 0;
  if(red_on) {
    red_on = 0;
    changed = 1;
  } else {
    red_on = 1;
    changed = 1;
  }
  return changed;            /* char changed checks if toggle was successful */
}

char toggle_green()          /* Toggles red led ON if OFF, or OFF if ON. */
{
  char changed = 0;
  if(green_on) {
    green_on = 0;
    changed = 1;
  } else {
    green_on = 1;
    changed = 1;
  }
  return changed;            /* char changed checks if toggle was successful */
}


/* State Machine section */

char state_zero() /* Display binary 0 */
{
  char checkR = 1;
  char checkG = 1;
  if(red_on) {
    checkR = toggle_red();
  }
  if(green_on) {
    checkG = toggle_green();
  }
  if(!checkR || !checkG) {
    return 0;
  } else {
    return 1;
  }
}

char state_one() /* Display binary 1 */
{
  char checkR = 1;
  char checkG = 1;
  if(red_on) {
    checkR = toggle_red();
  }
  if(!green_on) {
    checkG = toggle_green();
  }
  if(!checkR || !checkG) {
    return 0;
  } else {
    return 1;
  }
}

char state_two() /* Display binary 2 */
{
  char checkR = 1;
  char checkG = 1;
  if(!red_on) {
    checkR = toggle_red();
  }
  if(green_on) {
    checkG = toggle_green();
  }
  if(!checkR || !checkG) {
    return 0;
  } else {
    return 1;
  }
}

char state_three() /* Display binary 3 */
{
  char checkR = 1;
  char checkG = 1;
  if(!red_on) {
    checkR = toggle_red();
  }
  if(!green_on) {
    checkG = _green();
  }
  if(!checkR || !checkG) {
    return 0;
  } else {
    return 1;
  }
}

void state_loop() /* Loop through state 0 to 3 */
{
  char changed = 0;
  
  static char state = 0;
  char checkZero = 1;
  char checkOne = 1;
  char checkTwo = 1;
  char checkThree = 1;
  switch (state) {
  case 0:
    checkZero = state_zero();
    if(!checkZero) {changed = 0;}
    else {changed = 1;}
    led_changed = changed;
    led_update();
    state = 1; break;
  case 1:
    checkOne = state_one();
    if(!checkOne) {changed = 0;}
    else {changed = 1;}
    led_changed = changed;
    led_update();
    state = 2; break;
  case 2:
    checkTwo = state_two();
    if(!checkTwo) {changed = 0;}
    else {changed = 1;}
    led_changed = changed;
    led_update();
    state = 3; break;
  case 3:
    checkThree = state_three();
    if(!checkThree) {changed = 0;}
    else {changed = 1;}
    led_changed = changed;
    led_update();
    state = 0; break;
  }
}
