#include <stdio.h>

int main(void)
{
	int arr[10001] = {0, };
	int n, k;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		arr[k]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < arr[i]; j++)
			printf("%d\n", i);
	}
	return (0);
}
