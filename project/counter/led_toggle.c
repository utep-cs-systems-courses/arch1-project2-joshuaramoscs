#include <msp430.h>
#include "led.h"

char toggle_red()      // Toggles green led ON if OFF, or OFF if ON.
{
  char changed = 0;
  if(red_on) {
    red_on = 0;
    changed = 1;
  } else {
    red_on = 1;
    changed = 1;
  }
  return changed;
}

char toggle_green()     // Toggles green led On if OFF, or OFF if ON.
{
  char changed = 0;
  if(green_on) {
    green_on = 0;
    changed = 1;
  } else {
    green_on = 1;
    changed = 1;
  }
  return changed;      // char changed checks if toggle was successful
}
