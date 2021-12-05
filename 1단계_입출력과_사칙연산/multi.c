#include <stdio.h>

int main(void)
{
	int a, b;
	int b1, b10, b100;

	scanf("%d %d", &a, &b);
	b1 = b % 10;
	b10 = ((b - b1) % 100) / 10;
	b100 = b / 100;

	printf("%d\n", a * b1);
	printf("%d\n", a * b10);
	printf("%d\n", a * b100);
	printf("%d\n", a * b);
	return (0);
}