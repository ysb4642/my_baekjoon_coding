#include <stdio.h>
#include <limits.h>
#define MAX(a, b) a > b ? a : b

int main(void)
{
	int n, num, result = INT_MIN, sum = 0;
	
	scanf("%d", &n);

	while (n--)
	{
		scanf("%d", &num);
		sum = (MAX(sum, 0)) + num;
		result = MAX(sum, result);
	}
	printf("%d\n", result);
	return (0);
}