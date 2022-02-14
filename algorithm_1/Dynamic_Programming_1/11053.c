#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, i, j, min, max = 0;
	int *arr, *dp;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	dp = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);

		min = 0;
		dp[i] = 1;
		for (j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && min < dp[j])
				min = dp[j];
		}
		dp[i] = min + 1;
		if (max < dp[i])
			max = dp[i];
	}
	printf("%d", max);
	free(arr);
	free(dp);
	return (0);
}
