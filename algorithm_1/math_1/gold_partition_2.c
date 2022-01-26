#include <stdio.h>
#include <math.h>
#define MAX 1000000

int main(void)
{
	int number[MAX + 1] = {1, 1};
	int prime[80000];
	int t, n, idx, i, j, cnt;

	i = 2;
	idx = 0;
	while (i < MAX)
	{
		if (!number[i])
		{
			prime[idx++] = i;
			j = i;
			while (i <= sqrt(MAX) && i * j <= MAX)
			{
				number[i * j] = 1;
				j++;
			}
		}
		i++;
	}
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		i = 0;
		cnt = 0;
		while (prime[i] <= n)
		{
			if (!number[n - prime[i]])
				cnt++;
			i++;
		}
		printf("%d\n", (cnt + 1) / 2 );
	}
	return (0);
}