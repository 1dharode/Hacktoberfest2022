#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int pq[SIZE], f = 0, r = -1, item;
void pqinsert()
{
  int n, i, j, temp;
  if (r == SIZE - 1)
    printf("Queue is Full\n");
  else
  {
    printf("Enter the item\n");
    scanf("%d", &item);
    pq[++r] = item;
    n = r - f + 1;
    for (i = 0; i < n - 1; i++)
    {
      for (j = f; j < r; j++)
      {
        if (pq[j] < pq[j + 1])
        {
          temp = pq[j];
          pq[j] = pq[j + 1];
          pq[j + 1] = temp;
        }
      }
    }
  }
}
void pqdel()
{
  if (f > r)
    printf("queue is empty\n");
  else
    printf("item deleted=%d\n", pq[f++]);
}
void display()
{
  int i;
  if (f > r)
    printf("queue is empty\n");
  else
  {
    printf("Contents of queue\n");
    for (i = f; i <= r; i++)
      printf("%d\t", pq[i]);
  }
}

void main()
{
  int ch;
  for (;;)
  {
    printf("1. insert\n 2. delete\n 3. display\n 4. exit\n");
    printf("enter your ch\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      pqinsert();
      break;
    case 2:
      pqdel();
      break;
    case 3:
      display();
      break;
    default:
      exit(0);
      break;
    }
  }
}
