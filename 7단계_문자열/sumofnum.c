#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, i, sum;
	char *str;

	scanf("%d", &n);
	str = (char *)malloc(sizeof(char) * (n + 1));
	scanf("%s", str);
	str[n] = '\0';
	sum = 0;
	for(i = 0; i < n; i++)
		sum += str[i] - 48;
	printf("%d", sum);
	free(str);
	str = NULL;
	return (0);
}