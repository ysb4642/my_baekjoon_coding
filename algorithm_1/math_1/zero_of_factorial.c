#include <stdio.h>

int main(void)
{
	int n, cnt5, cnt25, cnt125;

	scanf("%d", &n);

	cnt5 = n / 5;
	cnt25 = n / 25;
	cnt125 = n / 125;

	printf("%d", cnt5 + cnt25 + cnt125);
	return (0);
}