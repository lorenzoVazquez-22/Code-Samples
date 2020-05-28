#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "formatTriple.h"
#include "findTriplets.h"
#include "header.h"

int main (int argc, char * argv [])
{
    if (argc <= 1){
        printf("\n    There must be exactly 2 command-line arguments:  argv[0] & perimeter.\n\n");
        return 0 ;
    } 
        
    unsigned long int perimeter = strtoul ( argv[1], NULL, 10 ) ;
    
    header(perimeter);
    
    char * result = malloc(sizeof(char *) * 30);

    char * triplets = findTriplets(perimeter);
  
    if (strcmp(triplets, "fail") == 0)
    {
        sprintf(result, "    -----------------------------------------------------------------------------------------------\n    No Pythagorean triples were found for the given perimeter, %lu.\n    -----------------------------------------------------------------------------------------------\n", perimeter);
        printf("%s\n", result);
    }
    else
    {
        printf("    Perimeter = %lu\n", perimeter);
        printf("                           a        b        c       Factorization\n");
        printf("                        -------  -------  -------    -------------\n");
        printf("%s\n", triplets);
        free(triplets);
    }
    free(result);
  
    
    return 1;
     
   
}