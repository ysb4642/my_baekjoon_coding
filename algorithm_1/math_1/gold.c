#include <stdio.h>
#include <math.h>

int isprime(int n)
{
	int i = 2;

	if (n <= 1)
		return (0);
	while (i <= sqrt(n))
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int gold(int n)
{
	int i, m;

	for (i = 3; i <= n; i++)
	{
		m = n - i;
		if (isprime(i) && isprime(m))
			return (i);
		i++;
	}
	return (0);
}

int main(void)
{
	int n, k;

	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break ;
		k = gold(n);
		if (k == 0)
		{
			printf("Goldbach's conjecture is wrong.\n");
			continue ;
		}
		printf("%d = %d + %d\n", n, k, n - k);
	}
	return(0);
}