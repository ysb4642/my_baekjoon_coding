#include <stdio.h>
#include <math.h>

int main(void)
{
	int m, n, i, j;
	int arr[1000001] = {0, };

	arr[0] = 1;
	arr[1] = 1;
	scanf("%d %d", &m, &n);
	for (i = 2; i <= sqrt(1000001); i++)
	{
		for (j = 2; i * j <= n; j++)
			arr[i * j] = 1;
	}

	for (i = m; i <= n; i++)
	{
		if (arr[i] == 0)
			printf("%d\n", i);
	}
	return (0);
}