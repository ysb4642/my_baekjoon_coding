#include <stdio.h>

int ft_is_prime(int n)
{
	int i;

	if (n <= 1)
		return (0);
	else if (n == 2147483647)
		return (1);
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}
int main(void)
{
	int m, n, i, sum, min;

	scanf("%d %d", &m, &n);

	sum = 0;
	for (i = m; i <=n; i++)
	{
		if (ft_is_prime(i))
		{
			if (sum == 0)
				min = i;
			sum += i;
		}
	}
	if (sum == 0)
		printf("-1\n");
	else
	{
		printf("%d\n", sum);
		printf("%d\n", min);
	}
	return (0);
}