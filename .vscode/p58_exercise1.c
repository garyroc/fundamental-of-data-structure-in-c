/*

Make the fewest change to Program 2.3 
so as to obtain a function that creates a two-dimentional array 
all of whose elements are set to 0. 
Test your new function.

-------
Program 2.3

#define MALLOC(p,s)\
        if(!((p) = malloc(s))){\
        fprintf(stderr,"Insufficient memory");\
        exit(EXIT_FAILURE);\
        }

int** make2dArray(int rows,int cols)
{
    int **x, i;

    MALLOC(x, rows * sizeof(*x));

    for(inti=0; i<rows; i++)
        MALLOC(x[i], cols * sizeof(**x));
    return x;
} 

------
*/

#include <stdlib.h>
#include <stdio.h>


#define CALLOC(p,n,s)\
        if (!((p) = calloc(n,s))) {\
            fprintf(stderr, "Insufficient memory");\
            exit(EXIT_FAILURE);\
        }

int** make2dArray(int rows, int cols)
{
    int **x;

    CALLOC(x,rows,sizeof(*x));

    for(int i=0;i<rows;i++)
        CALLOC(x[i],cols,sizeof(**x));
}