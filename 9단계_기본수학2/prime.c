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
	int N, i, a, cnt;

	scanf("%d", &N);
	cnt = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a);
		if (ft_is_prime(a))
			cnt++;
	}
	printf("%d\n", cnt);
	return (0);
}