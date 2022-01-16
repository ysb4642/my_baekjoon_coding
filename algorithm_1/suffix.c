#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	if (strcmp((char *)a, (char *)b) > 0)
		return 1;
	else if (strcmp((char *)a, (char *)b) < 0)
		return -1;
	return 0;
}

int main(void)
{
	char str[1000];
	char strs[1000][1000];
	int len, i;

	scanf("%s", str);
	len = strlen(str);
	for (i = 0; i < len; i++)
		*strs[i] = &str[i];
	qsort(strs, len, sizeof(strs[0]), compare);
	for (i = 0; i < len; i++)
		printf("%s\n", strs[i]);
	return (0);
}