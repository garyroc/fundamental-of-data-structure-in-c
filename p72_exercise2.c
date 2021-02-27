#define MAX_TERM 100

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    float coef;
    int expon;
} polynomial;

void readPoly(polynomial poly[],int *n)
{
    do
    {
        printf("\nPlease enter the number of term in your polynomial:");
        scanf("%d", n);
    } while (*n > MAX_TERM);

    printf("\n");

    for (int i = 0; i < *n;i++)
    {
        printf("\nCoefficient %d :", *n + 1);
        scanf("%f", &(poly + i)->coef);
        printf("\nExponantial %d :", *n + 1);
        scanf("%d", &(poly + i)->expon);
    }

    printf("\n");
}

void printPoly(polynomial poly[],int *n)
{
    printf("Your polynomials:");
    for (int i = 0; i < *n - 1;i++)
    {
        printf("%5.1fX^%d +",poly[i].coef , poly[i].expon );
    }
    if(!poly[*n-1].expon)
        printf("%5.1f\n", (poly + *n - 1) -> coef); 
    else
        printf("%5.1f*X^%d\n", poly[*n - 1].coef, poly[*n - 1].expon);
}

int main()
{
    int n;
    polynomial poly[MAX_TERM];
    readPoly(poly,&n);
    printPoly(poly,&n);
    return 0;
}