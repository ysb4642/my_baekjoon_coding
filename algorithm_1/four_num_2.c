#include <stdio.h>

int main(void)
{
	char arr[101];
	int a, b, c, d;
	long ab, cd;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	sprintf(arr, "%d%d %d%d", a, b, c, d);
	sscanf(arr, "%ld %ld", &ab, &cd);

	printf("%ld", ab + cd);
	return (0);
}
