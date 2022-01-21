#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b)
{
	return b ? GCD(b, a % b) : a;
}

int main(void)
{
	int d[100001];
	int n, s, k, i, res;

	scanf("%d %d", &n, &s);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);
		d[i] = abs(k - s);
	}
	res = d[0];
	for (i = 1; i < n; i++)
		res = GCD(res, d[i]);
	printf("%d", res);
	return (0);
}