#include <stdio.h>
#include <stdlib.h>
#define size 5
int dq[size], R = -1, F = -1, c = 0, n, i, ch, x;

void insertfront(int item)
{
    if (c == size)
    {
        printf("Queue is full\n");
    }
    else if (F == -1 && R == -1)
    {
        c++;
        F = R = 0;
        dq[F] = item;
    }
    else if (F == 0)
    {
        c++;
        F = size - 1;
        dq[F] = item;
    }
    else
    {
        c++;
        F--;
        dq[F] = item;
    }
}
void insertrear(int item)
{
    if (c == size)
    {
        printf("Queue is full");
    }
    else if (F == -1 && R == -1)
    {
        c++;
        F = R = 0;
        dq[R] = item;
    }
    else if (R == size - 1)
    {
        c++;
        R = 0;
        dq[R] = item;
    }
    else
    {
        c++;
        R++;
        dq[R] = item;
    }
}

void deletefront()
{
    if (c == 0)
    {
        printf("Queue is empty\n");
    }
    else if (F == R)
    {
        c--;
        printf("Number Deleted From Front End = %d\n", dq[F]);
        F = R = -1;
    }
    else if (F == size - 1)
    {
        c--;
        printf("Number Deleted From Front End = %d\n", dq[F]);
        F = 0;
    }
    else
    {
        c--;
        printf("Number Deleted From Front End = %d\n", dq[F]);
        F++;
    }
}

void deleterear()
{
    if (c == 0)
    {
        printf("Queue is empty\n");
    }
    else if (F == R)
    {
        c--;
        printf("Number Deleted From Rear End = %d\n", dq[R]);
        F = R = -1;
    }
    else if (R == 0)
    {
        c--;
        printf("Number Deleted From Rear End = %d\n", dq[R]);
        R = size - 1;
    }
    else
    {
        c--;
        printf("Number Deleted From Rear End = %d\n", dq[R]);
        R--;
    }
}

void display()
{
    if (c == 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        x = F;
        for (i = 1; i <= c; i++)
        {
            printf("%d\t", dq[x]);
            x = (x + 1) % size;
        }
        printf("\n");
    }
}

int main()
{
    for (;;)
    {
        printf("1. Add Rear\n");
        printf("2. Delete Rear\n");
        printf("3. Add Front\n");
        printf("4. Delete Front\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter a number:");
            scanf("%d", &n);
            insertrear(n);
            break;
        case 2:
            deleterear();
            break;
        case 3:
            printf("Enter a number:");
            scanf("%d", &n);
            insertfront(n);
            break;
        case 4:
            deletefront();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Wrong Choice\n");
        }
    }
    return 0;
}
