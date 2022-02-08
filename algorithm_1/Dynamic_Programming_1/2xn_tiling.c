#include <stdio.h>

int main(void)
{
	int n, i;
	int arr[1001];

	arr[0] = arr[1] = 1;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
		arr[i] = (arr[i - 1] + arr[i - 2])  % 10007;
	printf("%d", arr[n]);
	return (0);
}