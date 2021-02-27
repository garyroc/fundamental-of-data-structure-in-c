#define MAX_TERM 100

typedef struct{
    float coef;
    int expon;
} polynomial;

int pmult(polynomial poly1[],polynomial poly2[],polynomial poly3[],int n,int m)
{
    //polynomail multiplation poly1 * poly2 = poly3
    float temp[n * m];
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++)
            temp[poly1[i].expon + poly2[i].expon] = poly1[i].coef * poly2[i].coef;
    }

    int term = 0;
    for ( int i = 0; i < n * m;i++){
            if(temp[i]){
                poly3[term].expon = i;
                poly3[term++].coef = temp[i];
        }
    }

    return term;
}   


//time conplexity O(n*m)