#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char s[1000000];
	int *arr;
	int max, count, i, len;
	int idx;
	
	arr = (int *)calloc(26, sizeof(int));
	scanf("%s", s);
	len = strlen(s);
	
	for (i = 0; i < len; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			idx = s[i] - 'A';
		else if (s[i] >= 'a' && s[i] <= 'z')
			idx = s[i] - 'a';
		arr[idx]++;
	}
	max = arr[0];
	count = 0;
	idx = 0;
	for (i = 1; i < 26; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			idx = i;
		}
	}
	for (i = 0; i < 26; i++)
	{
		if (max == arr[i])
			count++;
	}
	if (count > 1)
		printf("%c", '?');
	else
		printf("%c", idx + 'A');
	free(arr);
	arr = NULL;
	return (0);
}