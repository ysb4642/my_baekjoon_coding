#include <stdio.h>

int main(void)
{
	int n, b, i, cnt = 0;
	int arr[100];

	scanf("%d %d", &n, &b);
	for (i = 0; n > 0; i++)
	{
		arr[i] = n % b;
		n /= b;
		cnt++;
	}
	for (i = cnt - 1; i >= 0; i--)
	{
		if (arr[i] < 10)
			printf("%d", arr[i]);
		else
			printf("%c", arr[i] + 55);
	}
	return (0);
}