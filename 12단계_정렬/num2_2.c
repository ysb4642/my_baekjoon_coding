#include <stdio.h>

#define MAX	1000001

int main(void)
{
	int arr[MAX * 2] = {0, };
	int n;

	scanf("%d", &n);
	int a;
	while (n--)
	{
		scanf("%d", &a);
		arr[a + MAX] = 1;
	}

	for (int i = 0; i < MAX * 2; i++)
	{
		if (arr[i])
			printf("%d\n", i - MAX);
	}
	return (0);
}