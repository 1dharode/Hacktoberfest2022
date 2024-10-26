#include <stdio.h>
#include <stdlib.h>
#define sz 5
int i;
void enqueue(int q[sz], int *f, int *r, int item)
{
	if (*r == sz - 1)
		printf("Queue is full.Enqueue not possible\n");
	else if (*f == -1 && *r == -1)
	{
		*f = *r = 0;
		q[*r] = item;
	}
	else
	{
		*r = *r + 1;
		q[*r] = item;
	}
}
void dequeue(int q[sz], int *r, int *f)
{
	if (*f == -1 && *r == -1)
		printf("Queue is empty.Dequeue not possible\n");
	else if (*f == *r)
	{
		*f = *r = -1;
	}
	else
	{
		printf("the item dequeued is %d\n", q[*f]);
		*f = *f + 1;
	}
}
void display(int q[sz], int *r, int *f)
{
	if (*f > *r)
		printf("Queue is empty.Nothing to display\n");
	else
	{
		printf("The elements in the queue are \n");
		for (i = *f; i <= *r; i++)
			printf("Queue[%d] ======> %d\n", i, q[i]);
	}
}
void main()
{
	int q[sz], r = -1, f = -1, item, ch;
	for (;;)
	{
		printf("Enter the option 1: Enqueue 2:Dequeue 3:Display\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter the element you want to enqueue\n");
			scanf("%d", &item);
			enqueue(q, &f, &r, item);
			break;
		case 2:
			dequeue(q, &r, &f);
			break;
		case 3:
			display(q, &r, &f);
			break;
		default:
			exit(0);
		}
	}
}
