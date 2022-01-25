#include <stdio.h>
#include <math.h>

void	ERATOS(int arr[])
{
	int i, j;

	arr[0] = 0;
	arr[1] = 0;
	for (i = 2; i < 1000001; i++)
		arr[i] = i;
	for (i = 2; i <= sqrt(1000000); i++)
	{
		if (arr[i])
		{
			for (j = 2; i * j <= 1000000; j++)
				arr[j * i] = 0;
		}
	}

}

int main(void)
{
	int t, n, i, cnt;
	int arr[1000001];

	ERATOS(arr);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		cnt = 0;

		for (i = 2; i < n; i++)
		{
			if (arr[i] + arr[n - i] == n)
			{
				cnt++;
				if (i == n - i)
					cnt++;
			}
		}
		printf("%d\n", cnt / 2);
	}
	return (0);
}