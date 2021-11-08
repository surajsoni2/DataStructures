#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <string.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *arr;
};

struct Stack *stack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (int *)malloc(capacity * sizeof(int));
    return stack;
}

int isFullStack(struct Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmptyStack(struct Stack *stack)
{
    return stack->top == -1;
}

void pushStack(struct Stack *stack, int item)
{
    if (isFullStack(stack))
    {
        printf("Stack overflow");
    }
    else
    {
        stack->top = stack->top + 1;
        stack->arr[stack->top] = item;
        printf("Item Pushed");
    }
}

void pop(struct Stack *stack)
{
    if (isEmptyStack(stack))
    {
        printf("Stack underflow");
    }
    else
    {
        stack->arr[stack->top] = 0;
        stack->top = stack->top - 1;
    }
}

void peek(struct Stack *stack)
{
    if (isEmptyStack(stack))
    {
        printf("Stack underflow");
    }
    else
    {
        printf("peek Value = %d\n", stack->arr[stack->top]);
    }
}

int isOperand(char element)
{
    return (element >= "A" && element <= "Z") || (element >= "a" && element <= "z");
}

int isleftpara(char element)
{
    return element == "(";
}

int isrightpara(char element)
{
    return element == ")";
}

int isopearator(char element)
{  
    return (element == "+"||element =="-"||element =="*"||element =="/");
}

int preced(char element)
{
    switch (element)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

void traverse(struct Stack *stack)
{
    printf("traverse\n");
    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d\n", stack->arr[i]);
    }
}
int Capacity;

int main()
{
    char Q[] = "(a+b)*(c-d)", P[sizeof(Q)],item;
    struct Stack *stack1=stack(sizeof(Q));
    strcat(Q,")");
    for (int i = 0; i < sizeof(Q)-1; i++)     
    {
        if (isoperand(Q[i]))
        {
            strcat(P,Q[i]);
        }
        if (isleftpara(Q[i]))   
        {
            pushStack(stack1,Q[i]);
        }
        if (isopearator(Q[i]))
        {
            while (isEmptyStack(stack1) && pres)
            {
                /* code */
            }
            
        }
        
        
        
    }
    
}
