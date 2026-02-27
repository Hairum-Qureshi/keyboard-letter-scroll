#include <stdio.h>
#include <ncurses.h>
#include <stdint.h>
#include "scroll.h"

#define BLACK 0
#define WHITE 1

void draw_grid(uint16_t pixels[8][8]) {
   for (int y = 0; y < 8; y++) {
     move(y, 0);
     for (int x = 0; x < 8; x++) {
      if (pixels[7 - x][y]) {
        attron(COLOR_PAIR(pixels[7 - x][y]));
        addch('#');
        attroff(COLOR_PAIR(pixels[7 - x][y]));
      }
      else {
        addch(' ');
      }
    }
  }
  refresh();
}

void fill_pixels(uint16_t pixels[8][8], uint16_t color) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      pixels[i][j] = color;
    }
  }
}

void openDisplay(void) {
  uint16_t pixel[8][8];
  initscr();
  start_color();
  init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
  fill_pixels(pixel, BLACK);

  draw_grid(pixel);
  endwin();
}

void clearDisplay(void) {
  uint16_t pixel[8][8];
  fill_pixels(pixel, BLACK);
  draw_grid(pixel);
}

void displayLetter(char letter, int xOffset, int yOffset) {
   uint16_t pixel[8][8];
   init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
   fill_pixels(pixel, BLACK);
   int xStart = xOffset;
   int yStart = yOffset;

   if(letter == 'H') {
     pixel[(yStart % 8 + 2) % 8][(1 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 2) % 8][(2 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 2) % 8][(3 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 2) % 8][(4 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 2) % 8][(5 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 2) % 8][(6 + xStart % 8) % 8] = WHITE;

     pixel[(yStart % 8 + 6) % 8][(1 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 6) % 8][(2 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 6) % 8][(3 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 6) % 8][(4 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 6) % 8][(5 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 6) % 8][(6 + xStart % 8) % 8] = WHITE;

     pixel[(yStart % 8 + 5) % 8][(3 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 3) % 8][(3 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 4) % 8][(3 + xStart % 8) % 8] = WHITE;

     draw_grid(pixel);
   }
   if(letter == 'Q') {
     pixel[(yStart % 8 + 2) % 8][(1 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 3) % 8][(1 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 4) % 8][(1 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 5) % 8][(1 + xStart % 8) % 8] = WHITE;

     pixel[(yStart % 8 + 1) % 8][(2 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 1) % 8][(3 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 1) % 8][(4 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 1) % 8][(5 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 2) % 8][(6 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 3) % 8][(5 + xStart % 8) % 8] = WHITE;

     pixel[(yStart % 8 + 6) % 8][(2 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 6) % 8][(3 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 6) % 8][(4 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 6) % 8][(5 + xStart % 8) % 8] = WHITE;

     pixel[(yStart % 8 + 2) % 8][(2 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 4) % 8][(4 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 5) % 8][(6 + xStart % 8) % 8] = WHITE;
     pixel[(yStart % 8 + 4) % 8][(6 + xStart % 8) % 8] = WHITE;

  /*
     pixel[2][1] = WHITE;
     pixel[3][1] = WHITE;
     pixel[4][1] = WHITE;
     pixel[5][1] = WHITE;
 */
 /*
     pixel[1][2] = WHITE;
     pixel[1][3] = WHITE;
     pixel[1][4] = WHITE;
     pixel[1][5] = WHITE;
     pixel[2][6] = WHITE;
     pixel[3][5] = WHITE;
 */
 /*
     pixel[6][2] = WHITE;
     pixel[6][3] = WHITE;
     pixel[6][4] = WHITE;
     pixel[6][5] = WHITE;
 */
 /*
     pixel[2][2] = WHITE;
     pixel[4][4] = WHITE;
     pixel[5][6] = WHITE;
     pixel[4][6] = WHITE;
*/
     draw_grid(pixel);
   }
}
