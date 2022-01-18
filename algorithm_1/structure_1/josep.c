#include <stdio.h>

int main(void)
{
	int n, k, i, j, cnt;
	int arr[5001] = {0, };

	scanf("%d %d", &n, &k);
	printf("<");
	j = 1;
	for (i = 0; i < n; i++)
	{
		cnt = 0;
		while (1)
		{
			if (arr[j] == 0)
				cnt++;
			if (cnt == k)
			{
				arr[j] = 1;
				if (i == n - 1)
					printf("%d>", j);
				else
					printf("%d, ", j);
				break ;
			}
			j++;
			if (j > n)
				j = 1;
		}
	}
	return (0);
}