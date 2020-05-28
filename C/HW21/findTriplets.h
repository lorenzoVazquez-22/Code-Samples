#ifndef FINDTRIPLETS_H
#define FINDTRIPLETS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "formatTriple.h"

int isPrimitive(unsigned long int a, unsigned long int b, unsigned long int c)
{
    int prim = 0;
    
    for (int i = 2; i <= a; i ++)
    {
        if (a % i == 0 && b % i == 0 && c % i == 0)
        {
            prim = i;
        }
    }
    return prim;
}

char * findTriplets ( unsigned long int p )
{
    
    char * trips = malloc (sizeof(char *) * 15);
    int a, b, c, left, right ;
    int found = 0;
    for ( a = 1 ; a < p ; a ++ ) // guarantees 0 < a
    {
        for ( b = (a+1) ; b < p ; b ++ ) // guarantees a < b
        {
        if ( a + b < p ) // guarantees c > 0
        {
            c = p - a - b ;
            right = (a*a) + (b*b);
            left = c*c;
            if ( b < c && right == left )
            {
                int prim = isPrimitive(a,b,c);
                if(found == 0)
                    sprintf(trips, "%s", formatTriple(prim,a,b,c));
                else
                    sprintf(trips + strlen(trips), "%s", formatTriple(prim,a,b,c));
                found = 1;
            }
        } 
      }
    } 
    if (found == 0)
    {
        return "fail";
    }
    return trips;
} 
          



#endif