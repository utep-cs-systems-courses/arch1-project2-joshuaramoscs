#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "led_toggle.h"
#include "buzzer.h"

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
  static char state = 0;
  
  switch (state) {
  case 0:
    if(!state_zero()) {led_changed = 0;}
    else {led_changed = 1;}
    state = 1; break;
  case 1:
    if(!state_one()) {led_changed = 0;}
    else {led_changed = 1;}
    state = 2; break;
  case 2:
    if(!state_two()) {led_changed = 0;}
    else {led_changed = 1;}
    state = 3; break;
  case 3:
    if(!state_three()) {led_changed = 0;}
    else {led_changed = 1;}
    state = 0; break;
  }
}
