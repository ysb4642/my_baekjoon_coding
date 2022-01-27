#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
	char arr[100];
	int len, sum, n, i;

	scanf("%s", arr);
	scanf("%d", &n);
	len = strlen(arr);

	sum = 0;
	for (i = len - 1; i >= 0; i--)
	{
		if (isdigit(arr[i]))
			sum += pow(n, len - 1 - i) * (arr[i] - '0');
		else
			sum += pow(n, len - 1 - i) * (arr[i] - 'A' + 10);
	}
	printf("%d", sum);
	return (0);
}
