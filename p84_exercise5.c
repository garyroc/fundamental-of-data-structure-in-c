#include <stdio.h>
#include <stdlib.h>

#define MAX_COL 10
#define MAX_TERM 101

typedef struct{
    int col;
    int row;
    int value;
} matrix;

int COMPARE(int a,int b)
{
    if( a > b)
        return 1;
    else if ( a == b)
        return 0;
    else
    {
        return -1;
    }
    
}

void storeSum(matrix d[],int *totalD,int row,int column,int *sum)
{
    /* if *sum != 0, then it aong with its row and column position is stored as the *totalD+1 entry in d */
    if ( *sum){
        if(*totalD < MAX_TERM) {
            d[++*totalD].row = row;
            d[*totalD].col = column;
            d[*totalD].row = row;
            *sum = 0;
        }
        else {
            fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERM);
        }
    }
}

void mmult (matrix a[], matrix b[],matrix d[])
{  /* multiply tow sparse matrice */

    if(a[0].col != b[0].row){
        fprintf(stderr, "Incompatible matrices");
        exit(EXIT_FAILURE);
    }

    /*modified point*/
    int startingPos[MAX_COL];

    int i, j;
    matrix newB[MAX_TERM];
    if(b->value > 0){
        for (i = 1; i < b->col;i++)
            startingPos[i] = 0;
        startingPos[0] = 1;
        for (i = 0; i < b->value;i++)
            startingPos[(a+i)->col + 1]++;
        for (i = 1; i < b[0].col;i++)
            startingPos[i] += startingPos[i - 1];
        for (i = 1; i <= a[0].value;i++){
            j = startingPos[b[i].col]++;
            newB[j].col = b[i].col;
            newB[j].row = b[i].row;
            newB[j].value = b[i].value;
        }
    }

    /*set boundry condition*/
    a[a[0].value + 1].row = a[0].row;
    newB[b[0].value + 1].col = b[0].col;
    newB[b[0].value + 1].row = 0;

    int sum = 0, row = a[1].row, column;
    int totalD = 0, rowBegin = 1;

    for (i = 1; i <= a[0].value;){
        column = newB[1].col;
        for (j = 1; j <= b[0].value + 1;){
            /* multiply row of a by column of b */
            if (a[i].row != row){
                storeSum(d, &totalD, row, column, &sum);
                i = rowBegin; 
                for (; newB[j].col == column;j++)   //why not while()?
                    ;
                column = newB[j].col;
            }
            else if (newB[j].col != column) {
                storeSum(d, &totalD, row, column, &sum);
                i = rowBegin; 
                column = newB[j].col;
            }

            else switch (COMPARE(a[i].col, newB[j].row)) {
                case -1: /*go to next term in 1 */
                    i++;
                    break;
                case 0:  /* add terms, go to next term in a and b*/
                    sum += (a[i++].value * newB[j++].value);
                    break;
                case 1:  /* advance to next term in b */
                    j++;
            }
        }
        /*End of for j<= totalB+1*/
        for (; a[i].row == row;i++)
            ;
        rowBegin = i;
        row = a[i].row;
    }
    /*End of for j<= totalA*/
    d[0].row = a[0].row;
    d[0].col = b[0].col;
    d[0].value = totalD;
}
