#include <stdio.h>
#include <stdlib.h>

#define MAX_COL 10

typedef struct{
    int col;
    int row;
    int value;
} matrix;

void store

void mmult (matrix a[], matrix b[],matrix d[])
{  /* multiply tow sparse matrice */

    if(a[0].col != b[0].row){
        fprintf(stderr, "Incompatible matrices");
        exit(EXIT_FAILURE);
    }

    /*set boundry condition*/
    a[a[0].value + 1].row = a[0].row;
    b[b[0].value + 1].col = b[0].col;
    b[b[0].value + 1].row = 0;

    /*modified point*/
    int startingPos[MAX_COL];

    int i, j;
    if(b->value > 0){
        for (i = 1; i < b->col;i++)
            startingPos[i] = 0;
        startingPos[0] = 1;
        for (i = 0; i < b->value;i++)
            startingPos[(a+i)->col + 1]++;
        for (i = 1; i < b[0].col;i++)
            startingPos[i] += startingPos[i - 1];
    }

    int t,sum = 0, row = a[1].row, column;

    for (i = 1; i < a[0].value;){
        for (j = 1; j < b[0].value + 1;){
        /* multiply row of a by column of b */
            if (a[i].row != row){
                storeSum(d, &d[0].value, row, column, &sum);
                i = 1;
                k = startingPos[b[j].col]++;
                column = b[k].value;
                for (;b)
            }
        }
    }
}
