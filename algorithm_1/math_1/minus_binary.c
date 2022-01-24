#include <stdio.h>

void minus_binary(int n)
{
	if (n == 0)
		return ;
	if (n % -2 == 0)
	{
		minus_binary(n / -2);
		printf("0");
	}
	else
	{
		minus_binary((n - 1) / -2);
		printf("1");
	}
}

int main(void)
{
	int n;

	scanf("%d", &n);
	if (n == 0)
	{
		printf("0");
		return (0);
	}
	minus_binary(n);
	return (0);
}