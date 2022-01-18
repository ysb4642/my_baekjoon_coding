#include <stdio.h>

int main(void)
{
	int a, b, c;
	int n1, n2, n3, n4;

	scanf("%d %d %d", &a, &b, &c);

	n1 = (a + b) % c;
	n2 = ((a % c) + (b % c)) % c;
	n3 = (a * b) % c;
	n4 = (((a % c) * (b % c)) % c);

	printf("%d\n%d\n%d\n%d\n", n1, n2, n3, n4);
	return (0);
}