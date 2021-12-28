#include <stdio.h>
#include <stdlib.h>

int compare(const void *first, const void *second)
{
	int a = *(int *)first;
	int b = *(int *)second;

	if (a < b)
		return (-1);
	else 
		return (1);
	return (0);
}

int main(void)
{
	int n, i, j ,k, cnt, len;
	int *arr;
	int *tep;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	tep = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	cnt = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			k = 0;
			if (arr[i] == tep[j])
			{
				k++;
				cnt++;
				break ;
			}
		}
		if (k == 0)
			tep[i] = arr[i];
	
	}
	for (i = 0; i < n; i++)
		printf("%d ", tep[i]);
	printf("\n");
	len = n - cnt;
	qsort(tep, len, sizeof(tep[0]), compare);
	for (i = 0; i < n; i++)
		printf("%d ", tep[i]);
	/*for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i] == tep[j])
			{
				printf("%d ", j);
				break ;
			}
		}
	}*/
	free(arr);
	free(tep);
	arr = NULL;
	tep = NULL;
	return (0);
}