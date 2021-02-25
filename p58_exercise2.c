/*

Program 2.3

#define MALLOC(p,s)\
        if(!((p) = malloc(s))){\
        fprintf(stderr,"Insufficient memory");\
        exit(EXIT_FAILURE);\
        }

int** make2dArray(int rows,int cols)
{
    int **x;

    MALLOC(x, rows * sizeof(*x));

    for(int i=0; i<rows; i++)
        MALLOC(x[i], cols * sizeof(**x));
    return x;
} 

*/

#include <stdlib.h>
#include <stdio.h>

#define MALLOC(p,s)\
        if(!((p) = malloc(s))){\
        fprintf(stderr,"Insufficient memory");\
        exit(EXIT_FAILURE);\
        }

int** make2dArray(int rows,int* length)
{
    int **x;

    MALLOC(x, rows * sizeof(*x));

    for(int i=0; i<rows; i++)
        MALLOC(x[i], length[i] * sizeof(**x));
    return x;
} 