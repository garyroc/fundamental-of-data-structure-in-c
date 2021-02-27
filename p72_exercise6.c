#define MAX_TERM 101
#define MAX_POLY 15

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    float coef;
    int expon;
} polynomial;

void readPoly(polynomial poly[][MAX_TERM],int term[],int *polyNum)
{
    do
    {
        printf("\nPlease enter the number of term in your polynomial %d:",*polyNum + 1);
        scanf("%d", term[*polyNum]);
    } while (term[*polyNum] > MAX_TERM);

    printf("\n");

    
    for (int i = 0; i < term[*polyNum];i++)
    {
        printf("\nCoefficient %d :", term[*polyNum] + 1);
        scanf("%f", poly[*polyNum][i].coef);
        printf("\nExponantial %d :", term[*polyNum] + 1);
        scanf("%d", poly[*polyNum][i].expon);
    }

    printf("\n");
}

void printPoly(polynomial poly[][MAX_TERM],int term[],int *polyNum)
{
    printf("Your polynomials:");
    for (int i = 0; i < *polyNum;i++){
        for (int j = 0; j < term[i];j++)
            printf("%5.1fX^%d +", poly[i][j].coef, poly[i][j].expon);
    }
    if(!poly[*polyNum][term[*polyNum]].expon)
        printf("%5.1f\n", poly [*polyNum][term[*polyNum]].coef); 
    else
        printf("%5.1f*X^%d\n", poly [*polyNum][term[*polyNum]].expon);
}

void pmult(polynomial poly[][MAX_TERM],int term[],int poly1,int poly2,int *polyNum)
{
    //polynomail multiplation poly1 * poly2 = poly3
    float temp[term[poly1] * term[poly2]];
    for (int i = 0; i < term[poly1];i++){
        for (int j = 0; j < term[poly2];j++)
            temp[poly[poly1][i].expon + poly[poly2][i].expon] = poly[poly1][i].coef * poly[poly2][i].coef;
    };
    *polyNum += 1;
    for ( int i = 0; i < term[poly1] * term[poly2];i++){
            if(temp[i]){
                poly[*polyNum][term[*polyNum]-1].expon = i;
                poly[*polyNum][term[*polyNum]-1].coef = temp[i];
                term[*polyNum]++;
            }
    }
} 

int main()
{
    int term[MAX_POLY],polyNum = 0;
    polynomial poly[MAX_POLY][MAX_TERM];
    readPoly(poly,term,&polyNum);
    printPoly(poly,term,&polyNum);
    return 0;
}