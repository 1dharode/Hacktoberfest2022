#include <stdio.h>
int fact(int n);
void main()
{
	int n;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	printf("The factorial is %d\n", fact(n));
}
int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}