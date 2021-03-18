#define MAX_QUEUE_SIZE 100

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int key;
} element;

element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

void queueFull()
{
    fprintf(stderr, "QUEUE is FULL!");
    exit(EXIT_FAILURE);
}

void queueEmpty()
{
    fprintf(stderr, "QUEUE is Empty!");
    exit(EXIT_FAILURE);
}

void addq(element item)
{/*add an item to the queue*/
    if(rear == MAX_QUEUE_SIZE-1)
        queueFull();
    queue[++rear] = item;
}

element deleteq()
{/*remove element at the front of the queue*/
    if(front == rear)
        queueEmpty();
    return queue[++front];
}