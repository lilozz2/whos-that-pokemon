#include "pokemon.h"
#define BACKGROUND 0xFF

unsigned char LINEBUFFER[Rx];



void DrawLine(const ITEM_POINTER *head, unsigned char line_n){
  unsigned char var;

  // Background
  for (var = 0; var < Rx; var++) LINEBUFFER[var] = BACKGROUND;

  ITEM_POINTER temp = *head;
  while (temp != NULL){
    unsigned char SPRITE_X, SPRITE_Y;
    SPRITE_X = pgm_read_byte_near(temp->SPRITE_XY);
    SPRITE_Y = pgm_read_byte_near(temp->SPRITE_XY + 1);

    int posX = temp->posX;
    int posY = temp->posY;
    int X_LOWER, X_UPPER, Y_LOWER, Y_UPPER;
    X_LOWER = posX - SPRITE_X/2;
    X_UPPER = X_LOWER + SPRITE_X - 1;
    Y_LOWER = posY - SPRITE_Y/2;
    Y_UPPER = Y_LOWER + SPRITE_Y - 1;

    int flip = 0;
    if (temp->flip){
      flip = SPRITE_X-1;
    }

    long SpritePointer = temp->SPRITE;
    if (line_n >= Y_LOWER && line_n <= Y_UPPER){
      unsigned char pos, pixel;
      for (pos = 0; pos < Rx; pos++){
        if (pos >= X_LOWER && pos <= X_UPPER){
          pixel = pgm_read_byte_near(SpritePointer + SPRITE_X*(line_n-Y_LOWER) + abs(pos-X_LOWER-flip));
          if (temp->shadow && pixel != 255) pixel = 0;
          if (pixel != ALPHA) LINEBUFFER[pos] = pixel;
        }
      }
    }
    
    temp = temp->next;
  }
  display.writeBuffer(LINEBUFFER, Rx);
}

void DrawScreen(const ITEM_POINTER *head){
  display.setX(0, 95);
  display.setY(0, 63);
  display.startData();
  unsigned char LINE_N;
  for (LINE_N = 0; LINE_N < Ry; LINE_N++){
    DrawLine(head, LINE_N);
  }
  display.endTransfer();
}
