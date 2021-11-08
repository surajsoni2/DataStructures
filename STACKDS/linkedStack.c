#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next;
} *top = NULL, *new, *temp;

void Push(int x)
{
    new = (struct stack *)malloc(sizeof(struct stack));
    new->data = x;
    new->next = NULL;

    if (top == NULL)
        top = new;
    else
    {
        new->next = top;
        top = new;
    }
}

void Pop()
{
    temp = top;
    top = top->next;
    free(temp);
}
void traverse()
{
    temp = top;
    if (top == NULL)
    {
        printf("underflow\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int dataitem, choice = 1;
    printf("1.> Push the element into stack\n");
    printf("2.> Traverse the stack\n");
    printf("1.> Pop the element into stack\n");
    printf("3.> Press 0 for end of process\n");
    printf("enter your choice\n");
    scanf("%d", &choice);
    while (choice == 1 || 2 || 3)
    {
        switch (choice)
        {
        case 1:
            printf("enter a element to push in stack\n");
            scanf("%d", &dataitem);
            Push(dataitem);
            break;
        case 2:
            traverse();
            break;
        case 3:
            Pop();
            break;
       
        }
        printf("enter your choice\n");
        scanf("%d", &choice);
        if (choice==0)
        {
            break;
        }
        
    }
}