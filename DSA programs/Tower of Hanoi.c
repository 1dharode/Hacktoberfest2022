#include <stdio.h>
void toh(int, int, int, int);
void main()
{
	int n;
	printf("Enter the number of disks\n");
	scanf("%d", &n);
	toh(n, 1, 2, 3);
}
void toh(int n, int s, int a, int d)
{
	if (n > 0)
	{
		toh(n - 1, s, d, a);
		printf("%d ============> %d\n", s, d);
		toh(n - 1, a, s, d);
	}
}