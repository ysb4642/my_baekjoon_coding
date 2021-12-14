#include <stdio.h>
#include <math.h>


int main(void)
{
	int t, n, i, j;
	int arr[10001] = {0, };

	arr[0] = 1;
	arr[1] = 1;
	for (i = 2; i < sqrt(10001); i++)
	{
		for (j = 2; j * i < 10001; j++)
			arr[i * j] = 1;
	}
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		j = n / 2;
		while(1)
		{
			if (!arr[j])
			{
				if(!arr[n - j])
				{
					printf("%d %d\n", j, n - j);
					break ;
				}
			}
			j--;
		}
	}
	return (0);
}
/*int is_prime(int n)
{
	int i;

	if (n <= 1)
		return (0);
	i = 2;
	while(i <= sqrt(n))
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int main(void)
{
	int t, n, i, k, j;

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		k = n / 2;
		while(k > 1)
		{
			if (is_prime(k))
			{
				j = n - k;
				if (is_prime(j))
				{
					printf("%d %d\n", k, j);
					break ;
				}
			}
			k--;
		}
	}
	return (0);
}*/