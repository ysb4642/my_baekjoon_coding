#include <stdio.h>

void sum_123(int n)
{
	int arr[12];
	int i;

	arr[0] = arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	if (n < 4)
	{
		printf("%d\n", arr[n]);
		return ;
	}
	else
	{
		for (i = 4; i <= n; i++)
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		printf("%d\n", arr[n]);
	}
}

int main(void)
{
	int t, n, i;

	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		sum_123(n);
	}
	return (0);
}