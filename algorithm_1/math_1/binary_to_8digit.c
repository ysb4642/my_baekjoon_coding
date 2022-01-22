#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr[1000003] = {'0', '0', };
	int arrlen;
	int i, j = 0;

	scanf("%s", arr + 2);
	arrlen = strlen(arr);

	for (i = arrlen % 3; i < arrlen; i += 3)
		printf("%d", (arr[i] - '0') * 4 + (arr[i + 1] - '0') * 2 + (arr[i + 2] - '0'));
	return (0);
}