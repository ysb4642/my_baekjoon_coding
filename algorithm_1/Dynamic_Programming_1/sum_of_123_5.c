#include <stdio.h>

void	sum_123(int n)
{
	long long arr[100001][4];
	int i;

	arr[1][1] = arr[2][2] = 1;
	arr[3][1] = arr[3][2] = arr[3][3] = 1;
	if (n < 4)
	{
		if (n == 1 || n == 2)
			printf("%lld\n", arr[1][1]);
		else
			printf("%lld\n", arr[3][1] + arr[3][2] + arr[3][3]);
		return ;
	}
	else
	{
		for (i = 4; i <= n; i++)
		{
			arr[i][1] = (arr[i - 1][2] + arr[i - 1][3]) % 1000000009;
			arr[i][2] = (arr[i - 2][1] + arr[i - 2][3]) % 1000000009;
			arr[i][3] = (arr[i - 3][1] + arr[i - 3][2]) % 1000000009;
		}
		printf("%lld\n", (arr[n][1] + arr[n][2] + arr[n][3]) % 1000000009);
	}
}

int main(void)
{
	int t, n, i;

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		sum_123(n);
	}
	return (0);
}