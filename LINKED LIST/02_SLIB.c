#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct node
{
    char name[20];
    int age;
    struct node *next;
} *start = NULL, *trav, *new, *temp;

void insertionAtBeg()
{
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter the name of student and his/her age\n");
    scanf("%s", new->name);
    scanf("%d", &new->age);
    new->next = NULL;
    if (start == NULL)
    {
        start = new;
        return;
    }
    else
    {
        new->next=start;
        start=new;
    }
    
}

void traverse()
{
    trav = start;
    int count = 1;
    printf("SR\tNAME\tAGE\n");
    if (start == 0)
    {
        printf("list is empty");
    }
    while (trav != NULL)
    {
        printf("%d.>\t%s\t%d\n", count, trav->name, trav->age);
        trav = trav->next;
        count++;
    }
}


int main()
{

     int choice = 1, more = 1, listsize;
    printf("enter size of list (how many students are in the class\t");
    scanf("%d", &listsize);
    while (more == 1 || listsize != 0) //
    {
        printf("enter a number of choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertionAtBeg();
            break;
        case 2:
            traverse();
            break;
      
        }

        listsize--;
        if (listsize == 0)
        {
            printf("List is Full\n");
        }
        printf("1 for Next and 0 for End");
        scanf("%d", &more);
    }

    getch();
}