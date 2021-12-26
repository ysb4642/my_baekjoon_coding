#include <stdio.h>

int main(void)
{
	int n, k, i, x;
	int arr[10] = {0, };

	scanf("%d", &n);
	while(n)
	{
		k = n % 10;
		arr[k]++;
		n /= 10;
	}
	for (i = 9; i >= 0; i--)
	{
		x = arr[i];
		if (x)
		{
			while(x--)
				printf("%d", i);
		}
	}
	return(0);
}