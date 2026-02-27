#include <stdio.h>
#include <ncurses.h>
#include <stdint.h>
#include "scroll.h"
#include <unistd.h>

int checkInput(int delay) {
    int ch = getch();

    if(ch == ERR) {
      usleep(delay * 1000);
      return 0;
    }

   switch(ch) {
     case KEY_LEFT:
        return 1;
     case KEY_RIGHT:
        return 2;
     case KEY_UP:
        return 3;
     case KEY_DOWN:
        return 4;
     case '\n':
        return 5;
     default:
        return 0;
   }

}
