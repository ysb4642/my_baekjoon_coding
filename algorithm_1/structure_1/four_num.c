#include <stdio.h>
#include <math.h>

int main(void)
{
	long n1, n2, n3, n4;
	long a, b, sum;
	int	k, digit;

	scanf("%ld %ld %ld %ld", &n1, &n2, &n3, &n4);

	k = n2;
	digit = 0;
	while(k > 0)
	{
		k /= 10;
		digit++;
	}
	a = n1 * pow(10, digit) + n2;

	k = n4;
	digit = 0;
	while(k > 0)
	{
		k /= 10;
		digit++;
	}
	b = n3 * pow(10, digit) + n4;

	sum = a + b;
	printf("%ld",sum);
	return(0);
}