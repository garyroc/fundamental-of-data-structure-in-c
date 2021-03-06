#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void charFrequency(char* string)
{
    double frequency[26], n = strlen(string);
    for (int i = 0; i < 26;i++){
        frequency[i] = 0;
    }
    for (int i = 0; i < n; i++){
        if(*(string+i) < 97) //convert capital letter to small letter
            *(string + i) += 32;
        frequency[*(string + i) - 97]++;
    }
    for (int i = 0; i < 26;i++){
        if(frequency[i])
            printf("%c : %f\n", i + 97, frequency[i] / n);
    }
}


int main()
{
    charFrequency("asdasdjijczcmnolwq"); // test caes
    return 0;
}