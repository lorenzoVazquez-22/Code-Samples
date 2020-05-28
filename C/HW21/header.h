#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>

void header (unsigned long int p)
{
printf("\n    ==  ===========================================================================================\n");
printf("    ==  For those right triangles that have perimeter equal to %lu, this program finds the possible\n", p);
printf("    ==  integer lengths of that triangle's sides. In other words, this program finds the\n");
printf("    ==  Pythagorean triples corresponding to the given perimeter, %lu.\n", p);
printf("    ==\n");
printf("    ==  The components of each Pythagorean triple (a,b,c) are ordered such that a < b < c.\n");
printf("    ==\n");
printf("    ==  For the given perimeter, the Pythagorean triples are listed in lexicographic order.\n");
printf("    ==\n");
printf("    ==  The program indicates which Pythagorean triples are primitive (i.e., which Pythagorean\n");
printf("    ==  triples have 1 as their greatest common divisor).\n");
printf("    ==\n");
printf("    ==  For each Pythagorean triple that is not primitive, that triple is also written as\n");
printf("    ==  the product of the GCD and a primitive triple.\n");
printf("    ==  ===========================================================================================\n\n");
}

#endif