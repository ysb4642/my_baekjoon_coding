#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, k, i, j;
	int *arr;
	
	scanf("%d %d", &n, &k);
	arr = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		arr[i] = i + 1;
	j = k - 1;
	printf("<");
	while(n != 0)
	{
		printf("%d", arr[k - 1]);
		if (n != 1)
			printf(", ");
		for (i = k - 1; i < n; i++)
			arr[i] = arr[i + 1];
		n--;
		k += j;
		while (k > n)
		{
			k -= n;
			if (n == 0)
				break ;
		}
	}
	printf(">");
	free(arr);
	arr = NULL;
	return (0);
}
