
#include <stdio.h>
#include <stdlib.h>
// creating a structure
// 1->2->3->4->5->6->7

struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
void appendAtLoc()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data1: ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    printf("Enter location: ");
    int loc;
    scanf("%d", &loc);

    // if we need to add at first node;
    if (loc == 1)
    {
        temp->link = head;
        head = temp;
    }
    // at any location
    else
    {
        struct node *prev = NULL, *current = head;
        int i = 1;
        while (i < loc)
        {
            prev = current;
            current = current->link;
            i++;
        }
        prev->link = temp;
        temp->link = current;
    }
}

void append()
{

    // the node which need to be added
    struct node *temp;
    // memory  allocated
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    // we have now head and we have to perform operatuions on that
    // checking if the list is empty or not
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *point;
        point = head;
        while (point->link != NULL)
        {
            point = point->link;
        }
        point->link = temp;
    }
}
void display()
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}
int main()
{

    int choice;
    while (1)
    {
        printf("\n1 : Append\n");
        printf("2 : Display\n");

        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            appendAtLoc();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(1);

        default:
            printf("Invalid operation\n");
            break;
        }
    }
}