#include <stdio.h>

int GCD(int a, int b)
{
	return b ? GCD(b, a % b) : a;
}

int main(void)
{
	int a, b;
	int big, small;
	int gcd, lcm;

	scanf("%d %d", &a, &b);

	big = a > b ? a : b;
	small = a < b ? a : b;

	gcd = GCD(big, small);
	lcm = a * b / gcd;
	printf("%d\n%d\n", gcd, lcm);
	return (0);
}