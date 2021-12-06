#include <stdio.h>

int main(void)
{
	int i, n, max;
	int arr[9];

	max = -1;
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &n);
		arr[i] = n;
	}
	for (i = 0; i < 9; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	for (i = 0; i < 9; i++)
	{
		if (max == arr[i])
			break ;
	}
	printf("%d %d", max, i + 1);
	return (0);
}