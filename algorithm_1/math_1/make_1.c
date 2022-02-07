#include <stdio.h>

int min(int a, int b)
{
	return (a > b ? b : a);
}

int main(void)
{
	int num, i;
	int arr[1000001];

	scanf("%d", &num);
	arr[1] = 0;

	for (i = 2; i <= num; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
	}
	printf("%d", arr[num]);
	return (0);
}