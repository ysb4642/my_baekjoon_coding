#include <stdio.h>
#include <stdlib.h>

#define MIN -4000
#define MAX	4000

int main(void)
{
	int arr[8001] = {0, };
	int *res;
	int n, num, sum = 0;
	int i, j, k = 0;
	int many = 1, index, count = 0;

	scanf("%d", &n);
	res = (int *)calloc(n, sizeof(int));

	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		arr[num + MAX]++;
		sum += num;
	}

	for (i = MIN; i <= MAX; i++)
	{
		for (j = 0; j < arr[i + MAX]; j++)
			res[k++] = i;
	}

	// 평균값
	printf("%0.f\n", (double)sum / n);
	// 중앙값
	printf("%d\n", res[(n - 1)/ 2]);
	// 최빈값
	for (i = MIN; i <= MAX; i++)
	{
		if (arr[i + MAX] >= many)
			many = arr[i + MAX];
			
	}
	for (i = MIN; i <= MAX; i++)
	{
		if (arr[i + MAX] >= many)
		{
			index = i;
			count++;
		}
		if (count == 2)
			break ;
	}
	printf("%d\n", index);
	// 범위
	printf("%d\n", res[n - 1] - res[0]);
	free(res);
	res = NULL;
	return (0);
}