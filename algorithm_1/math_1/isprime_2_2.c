#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void	ERATOS(int arr[], int n)
{
	int i, j;

	for (i = 0; i <= n; i++)
		arr[i] = i;
	arr[0] = 0;
	arr[1] = 0;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (arr[i])
		{
			for (j = 2; i * j <= n; j++)
				arr[i * j] = 0;
		}
	}
}

int main(void)
{
	int n, m, i;
	int *arr;

	scanf("%d %d", &m, &n);
	arr = (int *)malloc(sizeof(int) * (n + 1));
	ERATOS(arr, n);
	for (i = m; i <= n; i++)
	{
		if (arr[i])
			printf("%d\n", arr[i]);
	}
	free(arr);
	return (0);
}