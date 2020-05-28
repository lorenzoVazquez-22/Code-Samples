

#ifndef INSERT_H
#define INSERT_H
#include "ordered_list.h"
#include "node.h"
#include "isEmpty.h"

int insertFront ( struct ordered_list *const this, const int datum)
{
  if (this == NULL){ return 0;}
  
  struct node * np = malloc( sizeof(struct node) );
  
  if (np == NULL){return 0;}
  
  np -> datum = datum;
  
  np -> next = this->head;
  
  this->head = np;
  
  return 1;
}

int findInsert (struct ordered_list *const this, const int datum)
{
    struct node * first =  malloc( sizeof(struct node) );
    
    struct node * second =  malloc( sizeof(struct node) );
    
    struct node * neu = malloc (sizeof(struct node));
    
    if (second == NULL || first == NULL) {return 0;}
    
    first = this->head;
    
    second = first->next;
    
    int t = 0;
    
    while (second != NULL && second -> datum < datum)
    {
        first = second;
        second = second->next;
    }
    
    neu->datum = datum;
    
    if (neu == NULL){return 0;}
    
    if (second == NULL)
    {
        first->next = neu;
        neu->next = NULL;
    }
    else
    {
        first -> next = neu;
        neu->next = second;
    }
    return 1;
}

int insert (struct ordered_list *const this, const int datum)
{
    int res = 0;
    if (isEmpty(this) == 1)
    {
        res = insertFront(this, datum);
    }
    else
    {
        if (this->head->datum >= datum)
        {
            res = insertFront(this, datum);
        }
        else
        {
            res = findInsert(this, datum);
        }
    }
    return res;
}
#endif