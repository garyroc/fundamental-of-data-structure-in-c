#include <stdio.h>

#define MAX_TERM 101

typedef struct{
    int col;
    int row;
    int value;
} matrix;

void readMatrix (matrix matriX[])
{

    do
    {
    printf("\nPlease enter the number of term in your matrix: ");
    scanf("%d", &matriX -> value);
    } while (matriX->value > MAX_TERM);

    printf("\n");

    do
    {
    printf("\nPlease enter the row(colum) of your matrix:");
    scanf("%d", &matriX -> row);
    } while (matriX -> row * matriX -> row < matriX -> value);

    matriX -> col = matriX -> row;

    for (int i = 1; i <= matriX -> value;i++)
    {
        printf("\nrow of element %d :", i);
        scanf("%d", &(matriX + i)->row);
        printf("\ncolum of element %d :", i);
        scanf("%d", &(matriX + i)->col);
        printf("\nvalue of element %d :", i);
        scanf("%d", &(matriX + i)->value);
    }

}

void printMatrix (matrix matriX[])
{
    int counter = 1;
    for (int i = 0; i < matriX[0].row;i++){
        printf ("\n");
        for (int j = 0; j < matriX[0].col;j++){
            printf(" ");
            if( i == matriX[counter].row && j == matriX[counter].col)
            {
                printf("%3d", matriX[counter].value);
                counter++;
            }
            else
            {
                printf("  0");
            }
        }
    }
}

void search(matrix matriX[],int n)
{
    for (int i = 1; i <= matriX->value; i++){
        if(matriX[i].value == n){
            printf("row:%d colum:%d\n", matriX[i].row, matriX[i].col);
        }
    }
}


int main()
{
    matrix a[MAX_TERM];
    readMatrix(a);
    printMatrix(a);
    return 0;
}