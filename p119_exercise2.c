#define MAX_QUEUE_SIZE 100

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int key;
} element;

element queue[MAX_QUEUE_SIZE];
int rear = MAX_QUEUE_SIZE-1;
int front = MAX_QUEUE_SIZE-1;

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
{/* add an item to the queue */
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    if(front == rear)
        queueFull();
    queue[rear] = item;
}

element deleteq()
{/* remove front element from the queue*/
    if (front == rear)
        queueEmpty();
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}