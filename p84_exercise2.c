#include <stdio.h>

#define MAX_COL 10

typedef struct{
    int col;
    int row;
    int value;
} matrix;


void fastTranspose(matrix a[],matrix b[])
{
    int rowTerm[MAX_COL];

    if(a->value > 0){
        for (int i = 0; i < a->col;i++)
            rowTerm[i] = 0;
        for (int i = 0; i < a->value;i++)
            rowTerm[(a+i)->col]++;
        int counter = 1;
        for (int i = 0; i < a -> col;i++){
            for (int j = 0; j < rowTerm[i];j++){
                b[counter].row = a[counter].col;
                b[counter].col = a[counter].row;
                b[counter].value = b[counter].value;
                counter++;
            }
        }
    }   
}