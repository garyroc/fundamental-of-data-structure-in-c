#define MAX_TERM 101
#define MAX_POLY 15
#define COMPARE(a,b) ( a > b) ? 1:(a < b) ? -1:0

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

void padd (polynomial poly[][MAX_TERM],int term[],int poly1,int poly2,int *polyNum)
{
    int i = 0, j = 0,counter = 0;
    polyNum++;
    while(i <= poly1 && j < poly2){
        switch(COMPARE(poly[poly1][i].expon, poly[poly2][j].expon))
        {
            case 1 :
                poly[*polyNum][counter].expon = poly[poly1][i].expon;
                poly[*polyNum][counter++].coef = poly[poly1][i++].coef;
                break;
            case -1 :
                poly[*polyNum][counter].expon = poly[poly2][j].expon;
                poly[*polyNum][counter++].coef = poly[poly2][j++].coef;
                break;
            case 0 :
                poly[*polyNum][counter].expon = poly[poly1][i].expon;
                poly[*polyNum][counter++].coef = poly[poly1][i++].coef + poly[poly2][j++].coef;
        }
    }

    while(i <= poly1){
        poly[*polyNum][counter].expon = poly[poly1][i].expon;
        poly[*polyNum][counter++].coef = poly[poly1][i++].coef;
    }

    while(j <= poly2){
        poly[*polyNum][counter].expon = poly[poly2][j].expon;
        poly[*polyNum][counter++].coef = poly[poly2][j++].coef;
    }
}

void pmult(polynomial poly[][MAX_TERM],int term[],int poly1,int poly2,int *polyNum)
{
    //polynomail multiplation  poly[++polyNum][MAX_TERM] = poly[1][MAX_TERM] * poly[2][MAX_TERM]
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