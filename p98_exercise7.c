#include <stdio.h>
#include <string.h>

#define max_string_size 100
#define max_pattern_size 100

int failure[max_pattern_size];
char string[max_string_size];
char pat[max_pattern_size];

void fail(char *pat)
{/*Compute the pattern's failure function*/
    int n = strlen(pat);
    failure[0] = -1;
    for (int i, j = 1; j < n;j++){
        i = failure[j - 1];
        while((pat[j] != pat[i+1]) &&(i >=0))
            i = failure[i];
        if(pat[j] == pat[i+1])
            failure[j] = i + 1;
        else
            failure[j] = -1;
    }
}

int pmatch(char* string,char *pat)
{/*KMP algorithm*/
    int i = 0, j = o;
    int lens = strlen(string);
    int lenp = strlem(pat);
    while( i< lens && j < lenp){
        if(string[i] == pat[j]){
            i++;
            j++;
        }
        else if{
            
        } 
    }
}