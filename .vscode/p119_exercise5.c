#define MAX_SIZE 100

#include <stdlib.h>
#include <stdio.h>


typedef struct{
    int key;
} element;

element circle[MAX_SIZE];

int front = MAX_SIZE - 1;
int rear = MAX_SIZE - 1;

int size()
{
    if (front == rear)
        return 0;
    else if(rear > front)
        return rear - front;
    else
        return (MAX_SIZE - 1) - (front - rear);
}

element delete(int k)
{
    if(size() < k){
        fprintf(stderr, "Out of size!");
        exit(EXIT_FAILURE);
    }

    element item = circle[(front + k)%MAX_SIZE];
        
    if( k > (size()>>1)){
        for (int i = k; i < size();i++){
            circle[(front + i)%MAX_SIZE] = circle[(front + i + 1)%MAX_SIZE];
        }
        rear = (rear - 1) % MAX_SIZE;
    }  

    else
    {
        for (int i = k - 1; i >= 0;i--){
            circle[(front + i + 1)%MAX_SIZE] = circle[(front + i)%MAX_SIZE];
        }
        front = (front + 1) % MAX_SIZE;
    }
    return item;
}

void add(element item,int k)
{
    if(size() < k || size() + 1 == MAX_SIZE - 1){
        fprintf(stderr, "Out of size!");
        exit(EXIT_FAILURE);
    }

    if( k > (size()>>1)){
        for (int i = size(); i > k;i--){
            circle[(front + i + 1)%MAX_SIZE] = circle[(front + i)%MAX_SIZE];
        }
        rear = (rear + 1) % MAX_SIZE;
    }  

    else
    {
        for (int i = 0; i <= k;i++){
            circle[(front + i - 1)%MAX_SIZE] = circle[(front + i)%MAX_SIZE];
        }
        front = (front - 1) % MAX_SIZE;
    }
    
    circle[front + k + 1] = item;
}