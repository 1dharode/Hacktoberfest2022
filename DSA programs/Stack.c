#include <stdio.h>
#define SIZE 5
void push(int, int *, int[]);
void pop(int *, int[]);
void display(int *, int[]);
void main()
{
    int s[SIZE], top = -1, item, ch;
    while (1)
    {
        printf("\n 1: PUSH 2:POP 3:DISPLAY Otherwise EXIT\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element \n");
            scanf("%d", &item);
            push(item, &top, s);
            break;
        case 2:
            pop(&top, s);
            break;
        case 3:
            display(&top, s);
            break;
        default:
            printf("Invalid operation");
        }
    }
}
void push(int item, int *top, int s[])
{
    if (*top == SIZE - 1)
        printf("Stack if Full ");
    else
    {
        *top = *top + 1;
        s[*top] = item;
    }
}
void pop(int *top, int s[])
{
    if (*top == -1)
        printf("Stack is Empty");
    else
    {
        printf("The deleted element is %d", s[*top]);
        *top = *top - 1;
    }
}
void display(int *top, int s[])
{
    int i;
    if (*top == -1)
        printf("Stack is Empty");
    else
    {
        printf("The status of stack is \n");
        for (i = 0; i <= *top; i++)
            printf("%d ", s[i]);
    }
}