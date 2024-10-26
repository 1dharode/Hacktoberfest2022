#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
struct node
{
    char usn[10], name[10], branch[3];
    int sem, ph;
    struct node *next;
} *first = NULL, *temp = NULL, *temp1 = NULL, *temp2 = NULL;
void create()
{
    int sem, ph;
    char usn[10], name[10], branch[10];
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter Student details: \n");
    printf("Enter USN:");
    scanf(" %s", usn);
    printf("Enter Name:");
    scanf("%s", name);
    printf("Enter Branch:");
    scanf("%s", branch);
    printf("ENTER Semester:");
    scanf("%d", &sem);
    printf("ENTER Phone no:");
    scanf("%d", &ph);
    strcpy(temp->usn, usn);
    strcpy(temp->branch, branch);
    strcpy(temp->name, name);
    temp->sem = sem;
    temp->ph = ph;
    temp->next = NULL;
    count++;
}
void insertfront()
{
    create();
    if (first == NULL)
        first = temp;
    else
    {
        temp->next = first;
        first = temp;
    }
}
void insertlast()
{
    create();
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp1 = first;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
}
void deletefront()
{
    if (first == NULL)
    {
        printf("\nNo nodes in the list\n");
    }
    else
    {
        temp1 = first;
        first = first->next;
        free(temp1);
        count--;
    }
}
void deletelast()
{
    if (first == NULL)
    {
        printf("\nNo nodes in the list\n");
    }
    else
    {
        temp1 = first;
        while (temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2->next = NULL;
        free(temp1);
        count--;
    }
}
void display()
{
    if (first == NULL)
    {
        printf("\nNo nodes to display\n");
    }
    else
    {
        temp1 = first;
        printf("There are %d number of nodes in the list\n ", count);
        printf("Student Details are:\n");
        printf("USN \tNAME \tBRANCH \tSEM \tPHONE NUMBER\n");
        printf("\n-----------------------------------------------------\n");
        while (temp1 != NULL)
        {

            printf("%-3s\t %-10s %-3s\t %-3d %-10d\n", temp1->usn, temp1->name, temp1->branch, temp1->sem, temp1->ph);
            temp1 = temp1->next;
        }
    }
}
void main()
{
    int choice, m, i;
    printf("\n-->MENU<--\n");
    while (1)
    {
        printf("1.Create a SLL\n2.Display the records\n3.Insert at the last\n4.Delete at the last\n5.Insert at the front\n6.Delete at the front\n7.Exit\n");
        printf("Enter ur choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the number of student record to be created : ");
            scanf("%d", &m);
            for (i = 0; i < m; i++)
            {
                insertfront();
            }
            break;
        case 2:
            display();
            break;
        case 3:
            insertlast();
            break;
        case 4:
            deletelast();
            break;
        case 5:
            insertfront();
            break;
        case 6:
            deletefront();
            break;
        case 7:
            exit(1);
        default:
            printf("Invalid choice \n");
            break;
        }
    }
}
