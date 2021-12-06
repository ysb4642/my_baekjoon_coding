#include <stdio.h>
#include <string.h>

int main(void)
{
	int n, i, j, result, count;
	char str[80];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", str);
		result = 0;
		count = 1;
		for (j = 0; j < strlen(str); j++)
		{
			if (str[j] == 'O')
			{
				result += count;
				count++;
			}
			else
				count = 1;
		}
		printf("%d\n", result);
	}
	return (0);
}
