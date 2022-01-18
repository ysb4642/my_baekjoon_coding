#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];
	int len;

	scanf("%s", str);
	len = strlen(str);
	printf("%d", len);
	return (0);
}