#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
} coord;

void MergeTwoArea(coord arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int i;
	coord *sortArr = (coord *)malloc(sizeof(coord) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx].x < arr[rIdx].x)
			sortArr[sIdx] = arr[fIdx++];
		else if (arr[fIdx].x > arr[rIdx].x)
			sortArr[sIdx] = arr[rIdx++];
		else
		{
			if (arr[fIdx].y < arr[rIdx].y)
				sortArr[sIdx] = arr[fIdx++];
			else
				sortArr[sIdx] = arr[rIdx++];
		}
		sIdx++;
	}

	if (fIdx > mid)
	{
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else
	{
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];
	free(sortArr);
	sortArr = NULL;
}

void MergeSort(coord arr[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void)
{
	int n, i;
	coord *arr;

	scanf("%d", &n);
	arr = (coord *)malloc(sizeof(coord) * n);
	for (i = 0; i < n; i++)
		scanf("%d %d", &arr[i].x, &arr[i].y);
	MergeSort(arr, 0, n - 1);
	for (i = 0; i < n; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);
	free(arr);
	arr = NULL;
	return (0);
}