#include <stdio.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	return (strcmp((char *)a, (char *)b));
}

int main(void)
{
	char str[1001];
	char strs[1001][1001];
	int len, i, j;

	scanf("%s", str);
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		for (j = i; j < len; j++)
			strs[i][j - i] = str[j];
	}
	qsort(strs, len, sizeof(strs[0]), compare);
	for (i = 0; i < len; i++)
		printf("%s\n", strs[i]);
	return (0);
}