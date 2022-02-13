#include <stdio.h>

#define MOD 1000000000

int main(void)
{
	int n, i, j, sum;
	int dp[101][10];

	scanf("%d", &n);
	for (i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (i = 2; i <= n; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (j == 0)
				dp[i][0] = dp[i - 1][1] % MOD;
			else if (j == 9)
				dp[i][9] = dp[i - 1][8] % MOD;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}
	sum = 0;
	for (i = 1; i < 10; i++)
		sum = (sum + dp[n][i]) % MOD;
	printf("%d\n", sum);
	return (0);
}
