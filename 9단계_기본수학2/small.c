#include <stdio.h>

int main(void)
{
	int n, i;

	scanf("%d", &n);
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			printf("%d\n", i);
			n /= i;
			i--;
		}
	}
	if (n > 1)
		printf("%d\n", n);
	return (0);
}