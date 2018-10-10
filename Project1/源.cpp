#include<stdio.h>
int fun(unsigned X)
{
	int x;
	int a[3], m=0;
	a[0] = 10; a[1] = 2; a[2] = 9;
	for (x = 0; x < X - 1; x++)
		m += a[x];
}
main()
{
	unsigned a;
	a = 0;
	printf("%d", fun(a));
}