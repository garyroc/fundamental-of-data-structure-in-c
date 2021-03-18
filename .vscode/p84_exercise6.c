#define MAX_TERM 101
#define bool _Bool

#include<stdlib.h>

void madd(bool bitsA[], int valueA[], bool bitsB[], int valueB[],bool bitsD[],int valueD[])
{
    int counter = 0;
    for (int i = 0; i < MAX_TERM;i++){
        if (bitsA[i] && bitsB[i]){
            bitsD[i] = 1;
            valueD[counter] = valueA[counter] + valueB[counter];
            counter++;
        }
        else if (!bitsA[i] && !bitsB[i])
            bitsD[i] = 0;
        
        else{
            bitsD[i] = 1;
            valueD[counter] = (bitsA[i]) ? valueA[counter] : valueB[counter];
            counter++;
        }
    }
}
