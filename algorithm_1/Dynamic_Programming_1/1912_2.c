#include <stdio.h>
#define MAX(a, b) a > b ? a : b

int main(void)
{
	int n, num, result, sum;
	
	scanf("%d %d", &n, &sum);

	result = sum;
	while (--n)
	{
		scanf("%d", &num);
		sum = MAX(sum + num, num);
		result = MAX(result, sum);
	}
	printf("%d", result);
	return (0);
}