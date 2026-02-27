#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include "scroll.h"
#include <unistd.h>

int main(void) {
  char currLetter = 'H';
  initscr();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  int running = 1;
  int returnValue;
  int x = 0, y = 0;
  float xpos = 0.0, ypos = 0.0;
  float xspeed = 0.0, yspeed = 0.0;
  openDisplay();
  while(running) {
    clearDisplay();
    xpos += xspeed;
    ypos += yspeed;
    displayLetter(currLetter, (int) xpos, (int) ypos);
    returnValue = checkInput(1);
    // refresh();
    int sleepVal = 100000;
    usleep(sleepVal);
    switch(returnValue) {
      case 5:
        if(currLetter == 'Q') {
          running = 0;
        }
        currLetter = 'Q';
        xspeed = 0;  // Reset xpos to 0
        yspeed = 0;  // Reset ypos to 0
        displayLetter(currLetter, xpos, ypos);
        break;
      case 4:
        // y++;
        // y = (y + 1) % 8;
        // sleepVal = 100000;
        xspeed = xspeed > 1 ? 1.0 : xspeed + 0.1;
        // displayLetter(currLetter, y, x);
        break;
      case 3:
       // y--;
        xspeed = xspeed > 1 ? 1.0 : xspeed - 0.1;
       // x = (x - 1) % 8;
       // displayLetter(currLetter, y, x);
        break;
      case 2:
       // x++;
       yspeed = yspeed > 1 ? 1.0 : yspeed - 0.1;
       // y = (y + 1) % 8;
       // displayLetter(currLetter, y, x);
        break;
      case 1:
        // x--;
        yspeed = yspeed > 1 ? 1.0 : yspeed + 0.1;
        // y = (y - 1) % 8;
        // displayLetter(currLetter, y, x);
        break;
    }
  }

  endwin();
  return 0;
}
