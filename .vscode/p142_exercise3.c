/*multiple stacks*/
#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 10
#define MAX_STACK 2

typedef struct{
    int key;
} element;

element stacks[MEMORY_SIZE];
int bottom[MEMORY_SIZE], top[MEMORY_SIZE];

void stackfull(int stack)
{/*Search for free space in the array */

    /*form next one to the rightmost*/
    for (int i = stack + 1; i < MAX_STACK;i++){
        if((top[i] + 1)%MEMORY_SIZE != bottom[i+1]){
            /*move nearest circular stack for 1 free space*/
            if(top[i] < bottom[i]){
                for (int j = top[i]; j >= 0;j--)
                    stacks[(j + 1)%MEMORY_SIZE] = stacks[j];
                for (int j = MEMORY_SIZE - 1; j >= bottom[i];j--)
                    stacks[(j + 1)%MEMORY_SIZE] = stacks[j];
            }

            else{
                for (int j = top[i]; j >= bottom[i];j--)
                    stacks[(j + 1)%MEMORY_SIZE] = stacks[j];
            }
            top[i] = (top[i] + 1) % MEMORY_SIZE;
            bottom[i] = (bottom[i] + 1) % MEMORY_SIZE;
            return;
        }
    }

    /*form leftmost to the previous one */
    for (int i = 0; i < stack;i++){
        if((top[i] + 1)%MEMORY_SIZE != bottom[i+1]){
            /*move nearest circular stack for 1 free space*/
            if(top[i] < bottom[i]){
                for (int j = top[i]; j >= 0;j--)
                    stacks[(j + 1)%MEMORY_SIZE] = stacks[j];
                for (int j = MEMORY_SIZE - 1; j >= bottom[i];j--)
                    stacks[(j + 1)%MEMORY_SIZE] = stacks[j];
            }

            else{
                for (int j = top[i]; j >= bottom[i];j--)
                    stacks[(j + 1)%MEMORY_SIZE] = stacks[j];
            }
            top[i] = (top[i] + 1) % MEMORY_SIZE;
            bottom[i] = (bottom[i] + 1) % MEMORY_SIZE;
            return;
        }
    }

    /*don't have any free space*/
    fprintf(stderr, "run out of memory!");
    exit(EXIT_FAILURE);
}

void push(element item,int stack)
{
    if((top[stack] + 1)%MEMORY_SIZE == bottom[stack + 1])
        stackfull(stack);
    stacks[(++top[stack])%MEMORY_SIZE] = item;
}

