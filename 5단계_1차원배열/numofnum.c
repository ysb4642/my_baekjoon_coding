#include <stdio.h>

int main(void)
{
	int num, i, n, k;
	int arr[10] = {0, };

	num = 1;
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &n);
		num *= n;
	}
	while (num != 0)
	{
		k = num % 10;
		arr[k]++;
		num /= 10;	
	}
	for (i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
	return (0);
}