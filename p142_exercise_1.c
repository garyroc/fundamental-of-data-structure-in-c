#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 100

typedef struct{
    int key;
} element;

element dstack[MEMORY_SIZE];
int top0 = -1, top1 = MEMORY_SIZE;

void isStackEmpty(_Bool stack)
{
    if((!stack && top0 == -1) || (stack == 1 && top1 == MEMORY_SIZE) ){
        fprintf(stderr, "stack %d is empty!", stack);
        exit(EXIT_FAILURE);
    }
}

void isStackFull()
{
    if(top0 + 1 == top1 || top1 - 1 == top0){
        fprintf(stderr, "both stacks are full!");
        exit(EXIT_FAILURE);
    }
}


void push(element item,_Bool stack)
{
    isStackFull();
    if(!stack)
        dstack[++top0] = item;
    else
        dstack[--top1] = item;
}

element pop(_Bool stack)
{
    isStackEmpty(stack);
    if (!stack)
        return dstack[top0--];
    else
        return dstack[top1++];
}

