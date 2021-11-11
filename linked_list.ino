#include "pokemon.h"

void addItem(int posX, int posY, const long SPRITE_XY, const long SPRITE, unsigned char shadow, int flip, ITEM_POINTER *head){
  ITEM_POINTER item = (ITEM_POINTER) malloc(sizeof(ITEM));
  item->posX = posX;
  item->posY = posY;
  item->SPRITE_XY = SPRITE_XY;
  item->SPRITE = SPRITE;
  item->shadow = shadow;
  item->flip = flip;
  item->next = NULL;

  if (*head == NULL){
    *head = item;
  }
  else{
    ITEM_POINTER temp = *head;
    while (temp->next != NULL){
      temp = temp->next;
    }
    temp->next = item;
  }
}

void freeList(ITEM_POINTER* head)
{
   ITEM_POINTER tmp;
   while (*head != NULL){
       tmp = *head;
       *head = (*head)->next;
       free(tmp);
    }
}

void printList(ITEM_POINTER *head){
  ITEM_POINTER tmp = *head;
  while (tmp != NULL){
    Serial.println(tmp->posY);
    tmp = tmp->next;
  }
}
