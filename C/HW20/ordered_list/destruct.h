
#ifndef DESTRUCT_H 
#define DESTRUCT_H
#include "ordered_list.h"
#include "clear.h"
void destruct (struct ordered_list **this)
{
    clear(*this);
    free(*this);
    *this = NULL;
}
#endif
