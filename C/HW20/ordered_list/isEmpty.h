

#ifndef ISEMPTY_H
#define ISEMPTY_H
#include "ordered_list.h"

int isEmpty (struct ordered_list *const this)
{
    if (this == NULL || this->head == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#endif