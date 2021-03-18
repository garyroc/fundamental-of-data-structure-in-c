/*implement one stack and one queue in an array*/
#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 10

typedef struct{
    int key;
} element;

element circularArray[MEMORY_SIZE];
int top = - 1, front = MEMORY_SIZE, rear = MEMORY_SIZE;

void stackfull()
{
    if(front != MEMORY_SIZE){
        for (int i = 1; i <= front - rear;i++){
            circularArray[MEMORY_SIZE - i] = circularArray[front - i];
        }
        rear += MEMORY_SIZE - front;
        front = MEMORY_SIZE;
    }

    else{
        fprintf(stderr, "run out of memory!");
        exit(EXIT_FAILURE);
    }
}

void stackEmpty()
{
    fprintf(stderr, "stack is empty!");
    exit(EXIT_FAILURE);
}

void push(element item)
{
    if(top + 1 == rear)
        stackfull();
    circularArray[++top] = item;
}

element pop()
{
    if(top < 0)
        stackEmpty();
    return circularArray[top--];
}

void queueEmpty()
{
    fprintf(stderr, "queue is empty!");
    exit(EXIT_FAILURE);
}

void add(element item)
{
    if(rear - 1 == top)
        stackfull();
    circularArray[--rear] = item;
}

element dequeue()
{
    if(front == rear)
        queueEmpty();
    return circularArray[--front];
}


int main()
{
    element item;
    item.key = 9;
    add(item);
    item.key = 8;
    add(item);

    printf("%d\n", dequeue().key);
    printf("%d\n", dequeue().key);
    for (int i = 0; i < MEMORY_SIZE;i++){
        item.key = i;
        push(item);
    }

    
    for (int i = 0; i < MEMORY_SIZE;i++){
        printf("%d\n", pop().key);
    }

}