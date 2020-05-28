
#ifndef CLEAR_H
#define CLEAR_H

#include "ordered_list.h"
#include "deleteFront.h"

void clear (struct ordered_list *const this)
{
    if (this == NULL)
    {
        return;
    }
    else
    {
         while (this->head != NULL)
        {
            deleteFront(this);
        }
    }
   
}

#endif