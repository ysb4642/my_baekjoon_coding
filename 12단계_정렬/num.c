#include <stdio.h>
#include <stdlib.h>


void InserSort(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++)
	{
		insData = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break ;
		}

		arr[j + 1] = insData;
	}
}

int main(void)
{
	int n, i;
	int *arr;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);

	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	InserSort(arr, n);
	for (i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	free(arr);
	return (0);	
}