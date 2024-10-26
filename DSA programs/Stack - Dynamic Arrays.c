#include <stdio.h>
#include <stdlib.h>
int *stack, top = -1, i, capacity = 5;

void push(int ele)
{
    if (top == capacity - 1)
    {
        printf("Stack overflow\n");
        capacity++;
        printf("Stack size increased to %d\n", capacity);
        stack = (int *)realloc(stack, capacity * sizeof(int));
    }
    top++;
    stack[top] = ele;
    printf("%d pushed \n", ele);
}

int pop()
{
    int ele;
    if (top == -1)
    {
        printf("Stack underflow\n");
        exit(0);
    }
    else
    {
        ele = stack[top];
        printf("popped item is %d\n", ele);
        --top;
        capacity--;
        printf("Stack capacity decreased to %d\n", capacity);
        stack = (int *)realloc(stack, capacity * sizeof(int));
    }
}

void main()
{
    int ch, item;
    stack = (int *)malloc(capacity * sizeof(int));
    do
    {
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.Quit\n");

        printf("Enter your choice :\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element to push :\n");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            exit(0);
        }
    } while (ch != 3);
}
