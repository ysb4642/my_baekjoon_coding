#include <stdio.h>
#include <math.h>

void	ERATOS(int arr[])
{
	int i, j;

	arr[0] = 0;
	arr[1] = 0;
	for (i = 2; i <= 1000000; i++)
		arr[i] = i;
	for (i = 2; i <= sqrt(1000000); i++)
	{
		if (arr[i])
		{
			for (j = 2; i * j <= 1000000; j++)
				arr[i * j] = 0;
		}
	}
}

int main(void)
{
	int n, k, m;
	int arr[1000001];

	ERATOS(arr);
	while(1)
	{
		scanf("%d", &n);
		if (!n)
			break ;
		k = 3;
		m = n - 3;
		while (k <= m)
		{
			if (arr[k] && arr[m])
			{
				if (k + m == n)
					break ;
			}
			k += 2;
			m -= 2;
		}
		if (k > m)
			printf("Goldbach's conjecture is wrong.\n");
		else
			printf("%d = %d + %d\n", n, k, m);
	}
	return(0);
}