#include <stdio.h>
#include <stdlib.h>

int new_num(int num)
{
	int new_num;

	new_num = num;
	while (num > 0)
	{
		new_num += num % 10;
		num /= 10;
	}
	return (new_num);
}

int main(void)
{
	int i, num;
	int *arr;

	arr = (int *)calloc(10001, sizeof(int));
	if (!arr)
	{
		return (0);
		arr = NULL;
	}
	for (i = 1; i <= 10000; i++)
	{
		num = new_num(i);
		if (num <= 10000)
		arr[num] = 1;
	}
	for (i = 1; i < 10000; i++)
	{
		if (arr[i] == 0)
			printf("%d\n", i);
	}
	free(arr);
	arr = NULL;
	return (0);
}

/*int	main(void)
{
	int i, num, num_ad1, num_ad2;
	int *arr;

	arr = (int *)calloc(10001, sizeof(int));
	if (!arr)
		return (0);

	for (i = 1; i <= 10000; i++)
	{
		if (i < 100)
		{	
			num = i + (i / 10) + (i % 10);
			arr[num] = 1;
		}
		else if (i < 1000)
		{
			num = i + (i / 100) + ((i % 100) / 10) + ((i % 100) % 10);
			arr[num] = 1;
		}
		else if (i < 10000)
		{
			num = i + (i / 1000) + ((i % 1000) / 100) + (((i % 1000) % 100) / 10) + (i % 10);
			arr[num] = 1;
		}
		else
			break ;
	}
	
	for (i = 1; i < 10000; i++)
	{
		if (arr[i] == 0)
			printf("%d\n", i);
	}
	free(arr);
	return (0);
}*/