#include <stdio.h>
#include <stdlib.h>


int hailstoneCount(unsigned long int N)
{
  
    unsigned long int buffer = N;
      int count = 1;
    while (buffer != 1)
    {
        if (buffer % 2 == 0)
            buffer = buffer / 2;
        else
            buffer = (3 * buffer) + 1;
        count ++;
    }
    return count;

}

int main (int argc, char * argv [])
{
    if (argc <= 1){
        printf("\n    There must be exactly 2 command-line arguments:  argv[0] & L.\n\n");
        return 0 ;
    } 
        
    unsigned long int init = strtoul ( argv[1], NULL, 10 ) ;
    
    int i = 1;
    
    int c = hailstoneCount(i);
    
    while(c < init)
    {
         c = hailstoneCount(i);
         i++;
    }
    
    printf("\n    ==  ===========================================================================================\n");
    printf("    ==  %d is the least positive integer whose `hailstone sequence` is of length at least %lu.\n", i - 1, init);
    printf("    ==  ===========================================================================================\n\n");
    return 1;
}
