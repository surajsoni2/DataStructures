#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    char name[20];
    int age;
    struct node *next;
} *start = NULL, *trav, *new, *temp;

struct node * createnode(){
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

void recurReverse(struct node *newtemp){
    if (newtemp==NULL)
    {
        return;
    }
    recurReverse(newtemp->next);
    printf("1.>\t%s\t%d\n",newtemp->name,newtemp->age);
}

void iterReverse(struct node *current){
    struct node *prevNode=NULL,*nextNode;
    while (current != NULL){
        nextNode=current->next;
        current->next=prevNode;
        prevNode=current;
        current=nextNode;

    }
    start=prevNode;
}

int main()
{
    int choice = 1, more = 1, listsize;
    printf("enter size of list (how many students are in the class\t");
    scanf("%d", &listsize);
    while (more <= 1 || listsize != 0) //
    {
        printf("enter a number of choice");
        scanf("%d", &choice);

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
            recurReverse(start);
            
        case 5:
            iterReverse(start);
            break;
        }

        listsize--;
        
        if (listsize==0)
        {
            printf("List is filled\n");
        }
        printf("1 for Next and 0 for End");
        scanf("%d", &more);
    }
    

    getch();
}