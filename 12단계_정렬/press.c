#include <stdio.h>
#include <stdlib.h>

int compare(const void *first, const void *second)
{
	return (*(int *)first - *(int *)second);
}

int unique(int *arr, int size)
{
	int i, j = 0;
	for (i = 1; i < size; i++)
	{
		if (arr[j] == arr[i])
			continue ;
		arr[++j] = arr[i];
	}
	return (++j);
}

int binarysearch(int *arr, int size, int key)
{
	int left = 0, right = size - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] < key)
			left = mid + 1;
		else if (arr[mid] > key)
			right = mid - 1;
		else
			return mid;
	}
	return (-1);
}

int main(void)
{
	int n, i, cnt, tmp;
	int *arr;
	int *sort;

	scanf("%d", &n);

	arr = (int *)calloc(n ,sizeof(int));
	sort = (int *)calloc(n, sizeof(int));

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		sort[i] = arr[i];
	}

	qsort(sort, n, sizeof(int), compare);
	
	cnt = unique(sort, n);
	for (i = 0; i < n; i++)
	{
		tmp =  binarysearch(sort, cnt, arr[i]);
		printf("%d ", tmp);
	}
	free(arr);
	free(sort);
	arr = NULL;
	sort = NULL;

	return (0);
}
