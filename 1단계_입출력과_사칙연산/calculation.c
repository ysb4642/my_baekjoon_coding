#include <stdio.h>

int main(void)
{
	int a, b;

	scanf("%d %d", &a, &b);
	if (((1 <= a) && (a <= 10000)) && ((1 <= b) && (b <= 10000)))
	{
		printf("%d\n", a + b);
		printf("%d\n", a - b);
		printf("%d\n", a * b);
		printf("%d\n", a / b);
		printf("%d\n", a % b);
	}
	return (0);
}