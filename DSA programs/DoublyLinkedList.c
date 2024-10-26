#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int count = 0;
struct node
{
    struct node *prev;
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
    struct node *next;
} *head, *newnode, *temp, *temp1;

void create()
{
    int ssn, phno;
    float sal;
    char name[20], dept[10], desg[20];
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;
    printf("\n Enter ssn,name,department, designation, salary and phno of employee : ");
    scanf("%d %s %s %s %f %d", &ssn, name, dept, desg, &sal, &phno);
    newnode->ssn = ssn;
    strcpy(newnode->name, name);
    strcpy(newnode->dept, dept);
    strcpy(newnode->desg, desg);
    newnode->sal = sal;
    newnode->phno = phno;
    count++;
}
void insertbeg()
{
    if (head == NULL)
    {
        create();
        head = newnode;
        temp = head;
    }
    else
    {
        create();
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void insertend()
{
    if (head == NULL)
    {
        create();
        head = newnode;
        temp = head;
    }
    else
    {
        create();
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}
void displaybeg()
{
    temp1 = head;
    if (temp1 == NULL)
    {
        printf("List empty to display \n");
        return;
    }
    printf("\n Linked list elements from begining : \n");
    while (temp1 != NULL)
    {
        printf("%d %s %s %s %f %d\n", temp1->ssn, temp1->name, temp1->dept, temp1->desg, temp1->sal, temp1->phno);
        temp1 = temp1->next;
    }
    printf(" No of employees = %d ", count);
}
int deleteend()
{
    struct node *temp1;
    temp1 = head;
    if (temp1->next == NULL)
    {
        free(temp1);
        head = NULL;
        return 0;
    }
    else
    {
        temp1 = temp->prev;
        temp1->next = NULL;
        printf("%d %s %s %s %f %d\n", temp->ssn, temp->name, temp->dept,
               temp->desg, temp->sal, temp->phno);
        free(temp);
    }
    count--;
    return 0;
}
int deletebeg()
{
    struct node *temp1;
    temp1 = head;
    if (temp1->next == NULL)
    {
        free(temp1);
        head = NULL;
    }
    else
    {
        head = head->next;
        printf("%d %s %s %s %f %d", temp1->ssn, temp1->name, temp1->dept,
               temp1->desg, temp1->sal, temp1->phno);
        free(temp1);
    }
    count--;
    return 0;
}
int main()
{
    int ch, n, i;
    head = NULL;
    temp = temp1 = NULL;
    printf("-----------------MENU--------------------\n");
    printf("\n 1 - Create a DLL of n emp");
    printf("\n 2 - Display from beginning");
    printf("\n 3 - Insert at end");
    printf("\n 4 - delete at end");
    printf("\n 5 - Insert at beg");
    printf("\n 6 - delete at beg");
    printf("\n 7 - exit\n");
    printf("------------------------------------------\n");
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter no of employees : ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
                insertend();
            break;
        case 2:
            displaybeg();
            break;
        case 3:
            insertend();
            break;
        case 4:
            deleteend();
            break;
        case 5:
            insertbeg();
            break;
        case 6:
            deletebeg();
            break;
        case 7:
            exit(1);
        default:
            printf("wrong choice\n");
        }
    }
}
