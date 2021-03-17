#include <stdlib.h>

typedef struct listNode{
    int data;
    struct listNode *link;
}listNode,*listPointer;

/*exercise1*/
void delete(listPointer first,listPointer trail)
{/*delete x from the list, trail is the preceding node 
    and first is the front of the list*/
    listPointer tempPointer = (trail->link);
    if(trail)
        trail->link = (trail->link)->link;
    else
        first = first->link;
    free(tempPointer);
}

/*exercise2*/
listPointer searchList(listPointer first,int num)
{
    if(!first)
        return NULL;
    if(first->data == num)
        return first;
    else
        return searchList(first->link, num);
}

/*exercise3*/
void deleteNum(listPointer first,int num)
{
    

}