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
    char Q[] = "(a+b)*(c-d)", P[sizeof(Q)];
    // Q=strcat(Q,")");

    // this is all about stack creation

    int item, choice;
    system("color a");
    printf("enter the capacity of Stack ");
    scanf("%d", &Capacity);
    struct Stack *stack1 = stack(Capacity);
    char options[] = "9.> for displaying stack\n2.> for PUSH an elemnt to stack\n3.> for POP an elemnt from stack\n4.> for displaying Peek in stack\n0 for end\nenter choice ";

    for (choice = 1; choice != 0; printf("%s", options), scanf("%d", &choice))
    {

        switch (choice)
        {
        case 2:
            printf("enter item");
            scanf("%d", &item);
            pushStack(stack1, item);
            printf("\nPlease Wait 3 sec for next operation");
            sleep(3);
            break;
        case 3:
            pop(stack1);
            printf("\nPlease Wait 3 sec for next operation");
            sleep(3);
            break;
        case 4:
            peek(stack1);
            printf("\nPlease Wait 3 sec for next operation");
            sleep(3);
            break;
        case 9:
            traverse(stack1);
            printf("\nPlease Wait 3 sec for next operation");
            sleep(3);
            break;
        default:
            printf("Please enter a valid choice");
            sleep(2);
            break;
        }
        // printf("\r");
        system("cls");
    }
    if (choice == 0)
    {
        printf("Thank You So Much");
    }
}
