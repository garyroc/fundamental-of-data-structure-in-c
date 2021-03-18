#include <stdio.h>

#define MAX_COL 10

typedef struct{
    int col;
    int row;
    int value;
} matrix;


void fastTranspose(matrix a[],matrix b[])
{
    int startingPos[MAX_COL];

    int i, j;
    if(a->value > 0){
        for (i = 1; i < a->col;i++)
            startingPos[i] = 0;
        startingPos[0] = 1;
        for (i = 0; i < a->value;i++)
            startingPos[(a+i)->col + 1]++;
        for (i = 1; i < a[0].col;i++)
            startingPos[i] += startingPos[i - 1];
        for (i = 1; i <= a[0].value;i++){
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }   
}