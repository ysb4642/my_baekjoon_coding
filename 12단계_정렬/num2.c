#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fidx = left;
	int ridx = mid + 1;
	int i;

	int *sortArr = (int *)malloc(sizeof(int) * (right + 1));
	int sidx = left;

	while (fidx <= mid && ridx <= right)
	{
		if (arr[fidx] <= arr[ridx])
			sortArr[sidx] = arr[fidx++];
		else
			sortArr[sidx] = arr[ridx++];
		sidx++;
	}
	if (fidx > mid)
	{
		for (i = ridx; i <= right; i++, sidx++)
			sortArr[sidx] = arr[i];
	}
	else
	{
		for (i = fidx; i <= mid; i++, sidx++)
			sortArr[sidx] = arr[i];
	}
	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];
	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
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
	int *arr;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	if (!arr)
		return (0);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	MergeSort(arr, 0, n - 1);
	for (i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	free(arr);
	return(0);	
}