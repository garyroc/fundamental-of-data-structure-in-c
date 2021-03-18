#define MAX_QUEUE_SIZE 100

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int key;
} element;

element dqueue[MAX_QUEUE_SIZE];
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

void addQRear(element item)
{/* add an item to the rear of the queue */
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    if(front == rear)
        queueFull();
    dqueue[rear] = item;
}

void addQFront(element item)
{/* add an item to the front of the queue */
    int front_t = (!front) ? MAX_QUEUE_SIZE - 1 : front - 1;
    if(front_t == rear)
        queueFull();
    dqueue[front] = item;
    front = front_t;
}

element deleteQFront()
{/* remove front element from the queue*/
    if (front == rear)
        queueEmpty();
    front = (front + 1) % MAX_QUEUE_SIZE;
    return dqueue[front];
}

element deleteQRear()
{/* remove rear element from the queue*/
    if(front == rear)
        queueEmpty();
    element item = dqueue[rear];
    rear = (!rear) ? MAX_QUEUE_SIZE - 1 : (rear - 1);
    return item;
}