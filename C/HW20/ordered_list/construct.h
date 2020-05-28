
#ifndef CONSTRUCT_H
#define CONSTRUCT_H
#include <stdlib.h>
#include "ordered_list.h"

struct ordered_list* construct 	( )
{
    struct ordered_list * newList = malloc(sizeof(struct ordered_list));
    
    newList->head = NULL;
    
    return newList;
    
}
#endif