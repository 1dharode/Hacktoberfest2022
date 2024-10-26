#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, new;
    printf("Enter the number of elements to be inserted into array\n");
    scanf("%d", &n);
    int *ptr;
    ptr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
        scanf("%d", ptr + i);
    printf("The address is\n");
    for (int i = 0; i < n; ++i)
        printf("%d\n", (ptr + i));
    printf("Enter the new number of elements to be inserted into array\n");
    scanf("%d", &new);
    ptr = realloc(ptr, new * sizeof(int));
    for (int i = 0; i < new; ++i)
        scanf("%d", ptr + i);
    printf("The address is\n");
    for (int i = 0; i < new; ++i)
        printf("%d\n", (ptr + i));
    free(ptr);
}
