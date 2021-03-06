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

    }
}