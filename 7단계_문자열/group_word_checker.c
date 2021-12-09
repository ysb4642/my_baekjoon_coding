#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ft_checker(char *str)
{
	int len, j;
	char chr, temp;
	char *s;

	s = (char *)calloc(26, sizeof(char));
	len = strlen(str);

	for (j = 0; j < len; j++)
	{
		if (str[j] != str[j + 1])
		{
			chr = str[j];
			s[chr - 'a']++;
		}
	}
	for (j = 0; j < 26; j++)
	{
		if (s[j] > 1)
			return (0);
	}
	free(s);
	s = NULL;
	return (1);
}

int main(void)
{
	int n, i, cnt;
	char str[100];

	scanf("%d", &n);
	cnt = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%s", str);
		if (ft_checker(str))
			cnt++;
	}
	printf("%d", cnt);
	return (0);
}