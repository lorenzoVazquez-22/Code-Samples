#ifndef FORMAT_TRIPLE_H
#define FORMAT_TRIPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

 char * formatTriple(int prim, int a, int b, int c )
{
   char * result =  malloc(sizeof(char * ) * 12);
   
   sprintf(result , "%31d%9d%9d", a, b, c);
     if (prim)
   {
       sprintf(result + strlen(result), "    %d × (%d,%d,%d)\n", prim, (a / prim), (b / prim), (c / prim));
   }
   else
   {
       sprintf(result + strlen(result), "    %s\n", "Primitive!");
   }
   
    return result;
}
#endif
