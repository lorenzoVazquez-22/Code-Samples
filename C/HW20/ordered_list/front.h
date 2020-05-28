
#ifndef FRONT_H
#define FRONT_H
#include "ordered_list.h"
int front (const struct ordered_list *const this, DataType *returnDatum)

int front 	( const struct ordered_list *const this, int *const returnDatum ) 		
{
  if (this == NULL || this->head == NULL){return 0;}
  
  struct node * front = this->head;
  
  *returnDatum = front->datum;
   
  return 1;
}
#endif