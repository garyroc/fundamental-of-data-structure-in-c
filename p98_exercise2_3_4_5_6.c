#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

//2
void strndel(char* string,int start,int end)
{
    int n = strlen(string);
    if (start > n-1 || start < 0 || end >n-1 || end <0 || start > end ){
        fprintf(stderr, "Position is out of bounds");
        exit(EXIT_FAILURE);
    }
    strcpy(string + start, string + end);
}

//3
void strdel(char* string,char c)
{
    int n = strlen(string),i;
    for ( i = 0; i < n;){
        if (*(string + i) == c)
            break;
        i++;
    }

    strcpy(string + i,string +i+1);
}

//4
int strpos_1(char* string,char c)
{
    int n = strlen(string),i;
    _Bool found = FALSE;
    for ( i = 0; i < n;){
        if (*(string + i) == c){
                found = TRUE;
            break;
        }
        i++;
    }
    if(!found)
        return -1;

    return i;
}

//5
char* strchr_1(char* string,char c)
{
    int n = strlen(string),i;
    _Bool found = FALSE;
    for ( i = 0; i < n;){
        if (*(string + i) == c){
                found = TRUE;
            break;
        }
        i++;
    }
    if(!found)
        return NULL;

    return string + i;
}

//6
void strins(char *s, char *t,int i)
{
    if (i < 0 || i> strlen(s)) {
        fprintf(stderr, "Position is out of bounds");
        exit(EXIT_FAILURE);
    }

    if (!strlen(s))
        strcpy(s, t);
    else if (strlen(t)) {
        strcat(t, s + i);
        strcpy(s + i, t);
    }
}


