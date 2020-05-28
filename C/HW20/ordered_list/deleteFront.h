
#ifndef DELETEFRONT_H
#define DELETEFRONT_H
#include "ordered_list.h"
int deleteFront(struct ordered_list *const this)
{
  if (this == NULL){return 0;}
  if ( this->head == NULL) {return 0;}
  struct node * curHead = this->head;
  
  this->head = this->head->next;
  
  free(curHead);
  
  return 1;
}
#endif