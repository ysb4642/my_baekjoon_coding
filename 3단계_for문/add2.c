#include <stdio.h>

int main(void)
{
	int i, n, sum;

	sum = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		sum += i;
	printf("%d", sum);
	return (0);
}