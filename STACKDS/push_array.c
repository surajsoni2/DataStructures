#include <stdio.h>
#include <conio.h>
#define n 10

int stack[n], top = -1;

void push()
{
    int item;
    printf("enter th data item you want insert in the stack");
    scanf("%d", &item);
    if (top >= n - 1)
        printf("Overflow");
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}
void pop()
{
    if (top == 0)
        printf("underflow");
    else
    {
        int popped = stack[top];
        top = top - 1;
        printf("%d is popped from stack", popped);
    }
}

void traverse()
{
    printf("top == %d\n", top);
    printf("your stack contains %d elenments\n", top + 1);
    for (int i = top; i >= 0; i--)
    {
        printf("| %d |\n", stack[i]);
    }
}
int main()
{
    int choice = 1;
    printf("1.> for PUSH an elemnt to stack\n");
    printf("2.> for POP an elemnt from stack\n");
    printf("3.> for displaying elements in stack\n");
    printf(") for end\n");
    printf("enter your choice\n");
    scanf("%d", &choice);
    while (choice == 1 || choice == 2 || choice == 3)
    {
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            traverse();
            break;

        default:
            traverse();
            break;
        }
        printf("enter your choice\n");
        scanf("%d", &choice);
    }
}