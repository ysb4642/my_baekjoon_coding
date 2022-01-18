#include <stdio.h>
#include <math.h>

int isprime(int n)
{
	int i = 2;

	if (n == 1)
		return (0);
	while (i <= sqrt(n))
	{
		if (n % i == 0)
			return(0);
		i++;
	}
	return (1);
}

int main(void)
{
	int n, i, a, cnt = 0;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (isprime(a))
			cnt++;
	}
	printf("%d", cnt);
	return (0);
}