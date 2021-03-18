#include <math.h>

typedef struct {
    float coef;
    int expon;
}polynomial;


int peval(polynomial poly[],int n,int x){
    //horner's rule
    if(n == 1)
        return poly[0].coef * pow(x, poly[0].expon);
    for (int i = 0; i < n;i++)
        poly[i].expon -= poly[n-1].expon;
    return  pow(x, poly[n - 1].expon) * (peval(poly, n - 1, x) + poly[n-1].coef);
}

