#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp;

	temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
			low++;
		while (pivot <= arr[high] && high >= (left + 1))
			high--;
		if (low <= high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	int pivot;

	if (left <= right)
	{
		pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int main(void)
{
	int n, i, a;

	scanf("%d", &n);
	int arr[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a);
		arr[i] = a;
	}
	QuickSort(arr, 0, n - 1);
	printf("%d %d", arr[0], arr[n - 1]);
	return (0);
}