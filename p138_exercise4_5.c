#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING_SIZE 100


typedef struct
{
    int value;
    char *operator;
} element;

element stack[MAX_STACK_SIZE];
int top = -1;




void stackFull()
{
    fprintf(stderr, "Stack is full!,cannot add an element");
    exit(EXIT_FAILURE);
}

void stackEmpty()
{ 
    fprintf(stderr, "Stack is empty!,cannot pop an element");
    exit(EXIT_FAILURE);
}

void push(element  item)
{
    if(top >= MAX_STACK_SIZE)
        stackFull();
    stack[++top] = item;
}

element pop()
{
    if(top == -1)
         stackEmpty();
    return stack[top--];
}


char expr[6]="5 6 *";


typedef enum
{
    plus,
    minus,
    times,
    divide,
    mod,
    AND,
    OR,
    notEqual,
    less,
    greater,
    lessEqual,
    greaterEqual,
    leftShift,
    rightShift,
    eos,
    operand
} precedence;

precedence getToken(char *symbol,int *n)
{/*get the next token, symbol is the character representation 
    by its enumerated value, which is returned in the function name*/
    *n += sscanf((expr + *n), "c", symbol);
    printf("%d\n",*n);
    printf("%s", *symbol);

    if(!strcmp(symbol,"+"))  return plus;
    if(!strcmp(symbol,"-"))  return minus;
    if(!strcmp(symbol,"*"))  return times;
    if(!strcmp(symbol,"/"))  return divide;
    if(!strcmp(symbol,"%"))  return mod;
    if(!strcmp(symbol,"&&")) return AND;
    if(!strcmp(symbol,"||")) return OR;
    if(!strcmp(symbol,"!=")) return notEqual;
    if(!strcmp(symbol,"<"))  return less;
    if(!strcmp(symbol,">"))  return greater;
    if(!strcmp(symbol,"<=")) return lessEqual;
    if(!strcmp(symbol,">=")) return greaterEqual;
    if(!strcmp(symbol,"<<")) return leftShift;
    if(!strcmp(symbol,">>")) return rightShift;
    if(!strcmp(symbol,NULL))  return eos;
    printf("cc");
    return operand;
}

int eval()
{
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0; /*counter for the expression string*/
    token = getToken(&symbol,&n);

    printf("step1\n");
    while(token != eos) {
        printf("step3");
        element item;
        if (token == operand){
            item.value = atoi(&symbol);\
            printf("step2");
            push(item); /*stack insert*/
        }
        

        else {
            /*pop two operands, perform operation, and push result to the stack*/
            printf("step2");
            op2 = pop().value;
            op1 = pop().value;
            printf("step3");
            switch(token) {
                case plus:  item.value = op1 + op2;
                    break;
                case minus: item.value = op1 - op2;
                    break;
                case times: item.value = op1 * op2;
                    break;
                case divide:item.value = op1 / op2;
                    break;
                case mod:   item.value = op1 % op2;
                    break;
                case AND:   item.value = op1 && op2;
                    break;
                case OR:    item.value = op1 || op2;
                    break;
                case notEqual:item.value = op1 != op2;
                    break;
                case less:  item.value = op1 < op2;
                    break;
                case greater:item.value = op1 > op2;
                    break;
                case lessEqual:item.value = op1 <= op2;
                    break;
                case greaterEqual:item.value = op1 >= op2;
                    break;
                case leftShift:item.value = op1 << op2;
                    break;
                case rightShift:item.value = op1 >> op2;
                    break;
                default :
                    item.value = 0;
            }
            push(item);
            printf("step3");
        }
        token = getToken(&symbol,&n);
    }
    
    return pop().value;
}

int main()
{
    printf("%d\n",eval());
    return 0;
}