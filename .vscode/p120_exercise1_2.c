/*Dynamic Circular Queue*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MALLOC(p,s)\
        if(!((p) = malloc(s))){\
        fprintf(stderr,"Insufficient memory");\
        exit(EXIT_FAILURE);\
        }

typedef struct {
    char key;
} element;

void copy(element *start, element *end, element *newQueue);
void queueFull();
bool isEmpty();
element queueFront();
void addQ(element item);
element deleteQ();


element *queue;

int capacity = 8, front = 5, rear = 4;

int main()
{
    /*test case*/
    element q[8] = {{'c'}, {'d'}, {'e'}, {'f'}, {'g'}, {' '}, {'a'}, {'b'}};
    MALLOC(queue, 8 * sizeof(element));
    copy(q, q + 8, queue);
    for (int i = 0; i < 8;i++)
        printf("%c ",queue[i]);
    printf("\n");

    queueFull();

    for (int i = 0; i <= rear;i++)
        printf("%c ",queue[i]);

    return 0;
}





void copy(element *start,element *end,element *newQueue)
{
    for (int i = end - start ; i >= 0; i--)
        newQueue[i] = start[i];
}

void queueFull()
{
    /* allocate an array with twice the capacity */
    element *newQueue;
    MALLOC(newQueue, 2 * capacity * sizeof(*queue));

    int start = (front + 1) % capacity;

    /* copy from queue to newQueue  */
    if (start < 2)
        /* no warp around*/
        copy(queue + start,queue + start + capacity -1,newQueue);

    else
    {/* queue warps around*/
        copy(queue + start, queue + capacity, newQueue + capacity + start );

        copy(queue, queue + rear , newQueue + capacity - start);

        copy(newQueue + capacity + start , newQueue + 2 * capacity -1, newQueue);
    
    }

    /* switch to newQueue */
    front = 2 * capacity - 1;
    rear = capacity - 1; 
    capacity *= 2;
    free(queue);
    queue = newQueue;

}

void addQ(element item)
{/* add an item to the rear of the queue */
    rear = (rear + 1) % capacity;
    if(front == rear)
    queueFull();
    queue[rear] = item;
}

bool isEmpty()
{
    if(rear == front)
        return true;
    else
        return false;
}

element deleteQ()
{/* remove front element from the queue*/
    if (isEmpty()){
        fprintf(stderr, "Queue is empty!");
        exit(EXIT_FAILURE);
    }

    front = (front + 1) % capacity;
    return queue[front];
}

element queueFront()
{
    return queue[(front + 1) % capacity];
}



