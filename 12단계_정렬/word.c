#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char str[50];
	int len;
} string;

int compare(const void *first, const void *second)
{
	string *a = (string *)first;
	string *b = (string *)second;

	if (a->len < b->len)
		return (-1);
	else if (a->len > b->len)
		return (1);
	else
	{
		if (strcmp(a->str, b->str) < 0)
			return (-1);
		else
			return (1);
	}
	return (0);
}

int main(void)
{
	int n, i;
	string *s;

	scanf("%d", &n);
	s = (string *)malloc(sizeof(string) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", s[i].str);
		s[i].len = strlen(s[i].str);
	}
	qsort(s, n, sizeof(s[0]), compare);
	printf("%s\n", s[0].str);
	for (i = 1; i < n; i++)
	{
		if (strcmp(s[i].str, s[i - 1].str))
			printf("%s\n", s[i].str);
	}
	free(s);
	s = NULL;
	return (0);
}