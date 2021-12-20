#include <stdio.h>

int main(void)
{
	int n, m, i, j, k, sum, res;
	int arr[100];

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	res = 0;
	sum = 0;
	for(i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{	
			for (k = j + 1; k < n; k++)
			{
				sum = arr[i] + arr[j] + arr[k];
				if (sum > res && sum <= m)
					res = sum;
			}
		}
	}
	printf("%d\n", res);
	return (0);
}