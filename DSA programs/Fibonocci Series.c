#include <stdio.h>
int fib(int n); void main()
{
	int n;
	printf("Enter the value for n\n");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d\t", fib(i));
	}
}
int fib(int n)
{
	if (n == 0 || n == 1)
		return 0;
	if (n == 2)
		return 1;
	return fib(n - 1) + fib(n - 2);
}
