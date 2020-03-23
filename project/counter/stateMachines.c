#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "led_toggle.h"
#include "buzzer.h"

/* COMMENTED SECTION GOT MOVED TO led_toggle.s */

/*
char toggle_red()            //Toggles green led ON if OFF, or OFF if ON. 
{
  char changed = 0;
  if(red_on) {
    red_on = 0;
    changed = 1;
  } else {
    red_on = 1;
    changed = 1;
  }
  return changed;            // char changed checks if toggle was successful
}

char toggle_green()          //Toggles green led ON if OFF, or OFF if ON. 
{
  char changed = 0;
  if(green_on) {
    green_on = 0;
    changed = 1;
  } else {
    green_on = 1;
    changed = 1;
  }
  return changed;            // char changed checks if toggle was successful
}
*/


/* State Machine section */

/* Display binary 0 and buzz tone */
char state_zero()
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
    led_update();
    buzzer_set_period(0);
    return 1;
  }
}

/* Display binary 1 and buzz lower tone */
char state_one()
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
    led_update();
    buzzer_set_period(1000);
    return 1;
  }
}

/* Display binary 2 and buzz lower tone */
char state_two()
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
    led_update();
    buzzer_set_period(1500);
    return 1;
  }
}

/* Display binary 3 and buzz lower tone */
char state_three()
{
  char checkR = 1;
  char checkG = 1;
  if(!red_on) {
    checkR = toggle_red();
  }
  if(!green_on) {
    checkG = toggle_green();
  }
  if(!checkR || !checkG) {
    return 0;
  } else {
    led_update();
    buzzer_set_period(2000);
    return 1;
  }
}

/* Loop through state 0 to 3 */
void state_loop()
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
    state = 1; break;
  case 1:
    checkOne = state_one();
    if(!checkOne) {changed = 0;}
    else {changed = 1;}
    led_changed = changed;
    state = 2; break;
  case 2:
    checkTwo = state_two();
    if(!checkTwo) {changed = 0;}
    else {changed = 1;}
    led_changed = changed;
    state = 3; break;
  case 3:
    checkThree = state_three();
    if(!checkThree) {changed = 0;}
    else {changed = 1;}
    led_changed = changed;
    state = 0; break;
  }
}
