/*multiple mqueue*/

#include <stdlib.h>
#include <stdio.h>

#define MEMORY_SIZE 100
#define MAX_QUEUE 10

typedef struct{
    int key;
} element;

element mqueue[MEMORY_SIZE];
int front[MAX_QUEUE],rear[MAX_QUEUE];

void queueFull(int queue)
{/*search for free space*/

    /*form next one to the rightmost*/
    for (int i = queue + 1; i < MAX_QUEUE;i++){
        if(rear[i] != front[(i+1)%MAX_QUEUE]){
            if(front[i] > rear[i]){
                for (int j = MEMORY_SIZE - 1 ; j > front[i];j--)
                    mqueue[(j + 1) % MEMORY_SIZE] = mqueue[j];
                for (int j = rear[i]; j >= 0;j--)
                    mqueue[(j + 1) % MEMORY_SIZE] = mqueue[j];
            }
            else{
                for (int j = rear[i]; j > front[i];j--)
                    mqueue[(j + 1) % MEMORY_SIZE] = mqueue[j];
            }
            front[i] = (front[i] + 1) % MEMORY_SIZE;
            rear[i] = (rear[i] + 1) % MEMORY_SIZE;
            return;
        }
    }

    /*form leftmost to the previous one */
    for (int i = queue + 1; i < MAX_QUEUE;i++){
        if(rear[i] != front[(i+1)%MAX_QUEUE]){
            if(front[i] > rear[i]){
                for (int j = MEMORY_SIZE - 1 ; j > front[i];j--)
                    mqueue[(j + 1) % MEMORY_SIZE] = mqueue[j];
                for (int j = rear[i]; j >= 0;j--)
                    mqueue[(j + 1) % MEMORY_SIZE] = mqueue[j];
            }
            else{
                for (int j = rear[i]; j > front[i];j--)
                    mqueue[(j + 1) % MEMORY_SIZE] = mqueue[j];
            }
            front[i] = (front[i] + 1) % MEMORY_SIZE;
            rear[i] = (rear[i] + 1) % MEMORY_SIZE;
            return;
        }
        
    }

    /*don't have any free space*/
    fprintf(stderr, "run out of memory!");
    exit(EXIT_FAILURE);
}

void addq(element item,int queue)
{
    if(rear[queue] == front[(queue + 1)%MAX_QUEUE])
        queueFull(queue);
    mqueue[(++rear[queue]) % MEMORY_SIZE] = item;
}

void queueEmpty(int queue)
{
    fprintf(stderr, "queue %d is empty!", queue);
    exit(EXIT_FAILURE);
}

element deleteq(int queue)
{
    if(front[queue] == rear[queue])
        queueEmpty(queue);
    return mqueue[(++front[queue]) % MEMORY_SIZE];
}
