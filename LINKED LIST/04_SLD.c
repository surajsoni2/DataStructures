#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    char name[20];
    int age;
    struct node *next;
} *start = NULL, *trav, *new, *temp;

struct node *createnode()
{
    new = (struct node *)malloc(sizeof(struct node));
    printf("enter the name of student and his/her age\n");
    scanf("%s", new->name);
    scanf("%d", &new->age);
    new->next = NULL;
    return new;
}

// this function is used to insert a new node in LL in end of linked list
void insertionAtEnd()
{

    if (start == NULL)
    {
        start = createnode();
        return;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = createnode();
        return;
    }
}

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
        new->next = start;
        start = new;
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

void deletionAtBeg()
{
    struct node *delnode;
    delnode = start;
    start = start->next;
    free(delnode);
}
void deletionAtEnd()
{
    struct node *delnode, *tempptr2;
    tempptr2 = start;
    temp = start->next;
    while (temp->next != NULL)
    {
        tempptr2 = temp;
        temp = temp->next;
    }
    tempptr2->next = NULL;
    free(temp);
}

int main()
{
    int choice = 1, listsize;
    printf("enter size of list (how many students are in the class\t");
    scanf("%d", &listsize);
    printf("1.\t Insert new student in Last of list\n");
    printf("2.\t Insert new student in Beginning of list\n");
    printf("3.\t traverse the list\n");
    printf("4.\t deletion a student in Beginning of list\n");
    printf("5.\t Insert s student in end of list\n");
    printf("0 for end the process");
    printf("enter a number of choice");
    scanf("%d", &choice);
    while ((choice==1||2||3||4||5) || listsize != 0) //
    {

        switch (choice)
        {
        case 1:
            insertionAtEnd();
            if (listsize == 0)
            {
                printf("List is Full\n");
                break;
            }
            break;
        case 2:
            insertionAtBeg();
            break;
        case 3:
            traverse();
            break;
        case 4:
            deletionAtBeg();
            break;
        case 5:
            deletionAtEnd();
            break;
        
        }

        listsize--;

        printf("enter your choice");
        scanf("%d", &choice);
    }

    getch();
}