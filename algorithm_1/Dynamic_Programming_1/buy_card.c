#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, i, j, max = 0;
	int *arr, *dp;

	scanf("%d", &n);
	arr = (int *)calloc(n + 1, sizeof(int));
	dp = (int *)calloc(n + 1, sizeof(int));

	for (i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if (max < arr[j] + dp[i - j])
				max = arr[j] + dp[i - j];
		}
		dp[i] = max;
	}
	printf("%d", dp[n]);
	free(arr);
	free(dp);
	return (0);
}