#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
	int n, i, j, cnt;
	int arr[246913] = {0, };

	arr[0] = 1;
	arr[1] = 1;
	for(i = 2; i <= sqrt(246913); i++)
	{
		for (j = 2; i * j <= 246913; j++)
			arr[i * j] = 1;
	}
	while(1)
	{
		scanf("%d", &n);
		if (n == 0)
			break ;
		cnt = 0;
		for (i = n + 1; i <= 2 * n; i++)
		{
			if (arr[i] == 0)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return (0);
}
