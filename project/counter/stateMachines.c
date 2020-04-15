#include <msp430.h>
#include "states.h"
#include "led.h"
#include "led_toggle.h"
#include "buzzer.h"

/* Loop through state 0 to 3 */
void state_loop()
{
  static char state = 0;

  switch(state) {
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
