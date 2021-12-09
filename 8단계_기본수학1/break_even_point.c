#include <stdio.h>

int main(void)
{
	int a, b, c, point;
	scanf("%d %d %d", &a, &b, &c);

	if (b >= c)
		printf("-1");
	else
	{
		point = (a / (c - b)) + 1;
		printf("%d", point);
	}
	return (0);
}