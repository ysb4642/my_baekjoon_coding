#include <stdio.h>
#define PI	3.14159265359

int main(void)
{
	int r;
	double x, y;

	scanf("%d", &r);

	x = r * r * PI;
	y = r * r * 2;

	printf("%f\n%f\n", x, y);
	return (0);
}