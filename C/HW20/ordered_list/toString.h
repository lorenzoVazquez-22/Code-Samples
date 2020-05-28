

#ifndef TOSTRING_H
#define TOSTRING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordered_list.h"

void toString ( const struct ordered_list *const this, char *const buffer) 	
{
  if (this == NULL){
    strcpy(buffer, "");
  }
  else if (this->head == NULL)
  {
    strcpy(buffer, "[]");
  }
  else{
    
    struct node * unit = this->head;
    sprintf(buffer, "[");
    while (unit != NULL)
    {
      int data = unit->datum; 
      if (data != NULL)
      {
        if (unit->next != NULL)
          sprintf(buffer + strlen(buffer), "%d,", data);
        else
          sprintf(buffer + strlen(buffer), "%d]", data);
      }
      unit = unit->next;
    }
  }
  
}

#endif 