#include <stdio.h>

int main(void)
{
	int x, y, w, h, k, j;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	k = x < y ? x : y;
	j = w - x < h - y ? w - x : h - y;
	if (k < j)
		printf("%d\n", k);
	else
		printf("%d\n", j);
	return (0);
}