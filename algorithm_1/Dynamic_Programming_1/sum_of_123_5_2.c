#include <stdio.h>

#define N 1000000009

int main(void)
{
	unsigned t, n, i, arr[100001][4] = {{0, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 1, 1, 1}};
	for (i = 4; i < 100001; i++)
	{
		arr[i][1] = (arr[i - 1][2] + arr[i - 1][3]) % N;
		arr[i][2] = (arr[i - 2][1] + arr[i - 2][3]) % N;
		arr[i][3] = (arr[i - 3][1] + arr[i - 3][2]) % N;
	}
	scanf("%d", &t);
	while(t--)
	{
		scanf("%u", &n);
		printf("%u\n", (arr[n][1] + arr[n][2] + arr[n][3]) % N);
	}
	return (0);
}