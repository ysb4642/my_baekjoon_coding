#include <stdio.h>

/*int GCD(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return GCD(b, a % b);
}
*/
int GCD(int a, int b)
{
	return (b ? GCD(b, a % b) : a);
}

int main(void)
{
	int i, n, a, b, big, small;
	int gcd, lcm;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d", &a, &b);
		big = a > b ? a : b;
		small = a > b ? b : a;
		gcd = GCD(a, b);
		lcm = a * b / gcd;
		printf("%d\n", lcm);
	}
	return (0);
}