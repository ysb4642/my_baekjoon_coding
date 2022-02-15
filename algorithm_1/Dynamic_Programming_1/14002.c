#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, i, j, k, min, max = 0;
	int *arr, *dp, *a;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	dp = (int *)malloc(sizeof(int) * n);
	a = (int *)malloc(sizeof(int) * n);
	k = 0;
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
		{
			max = dp[i];
			a[k++] = arr[i];
		}
	}
	printf("%d\n", max);
	for (k = 0; k < max; k++)
		printf("%d ", a[k]);
	free(arr);
	free(dp);
	free(a);
	return (0);
}