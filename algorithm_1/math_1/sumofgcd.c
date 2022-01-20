#include <stdio.h>

int GCD(int a, int b)
{
	return b ? GCD(b, a % b) : a;
}

int main(void)
{
	int t, n, i, j, k;
	long long sum;
	int arr[100];

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		for (j = 0; j < n; j++)
			scanf("%d", &arr[j]);
		sum = 0;
		for (j = 0; j < n - 1; j++)
		{
			for (k = j + 1; k < n; k++)
				sum += GCD(arr[j], arr[k]);
		}
		printf("%lld\n", sum);
	}
	return (0);
}