#include <stdio.h>
#include <stdlib.h>
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

int main(void)
{
	int m, n, len;
	int *arr;
	
	scanf("%d %d", &m, &n);
	len = n - m + 1;
	arr = (int *)malloc(sizeof(int) * len);
	for (int i = 0; i < len; i++)
		arr[i] = m++;
	for (int i = 0; i < len; i++)
	{
		if (isprime(arr[i]))
			printf("%d\n", arr[i]);
	}
	free(arr);
	return (0);
}