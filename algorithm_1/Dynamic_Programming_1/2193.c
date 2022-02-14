#include <stdio.h>

int main(void)
{
	int n, i;
	long long dp[91] = {0, 1, 1};

	scanf("%d", &n);
	for (i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	printf("%lld\n", dp[n]);
	return (0);
}