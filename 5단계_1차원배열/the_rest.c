#include <stdio.h>

int main(void)
{
	int i, j, a, k, count, result;
	int arr[10];

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a);
		k = a % 42;
		arr[i] = k;
	}
	result = 0;
	for (i = 0; i < 10; i++)
	{	
		count = 0;
		for (j = i + 1; j < 10; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
				break ;
			}
		}
		if (count == 0)
			result++;
	}
	printf("%d", result);
	return (0);
}