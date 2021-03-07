#define MAX_STACK_SIZE 100
#define TRUE 1
#define FALSE 0
typedef struct{
    int key;
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

_Bool IsEmpty()
{
    if (top < 0)
        return TRUE;
    else
        return FALSE;
}