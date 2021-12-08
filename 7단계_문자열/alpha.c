#include <stdio.h>
#include <string.h>

int main(void)
{
	int j, str_len, count;
	char i;
	char str[100];
	
	scanf("%s", str);
	str_len = strlen(str);
	i = 'a';
	for (i = 'a'; i <= 'z'; i++)
	{
		count = 0;
		for (j = 0; j < str_len; j++)
		{
			if (str[j] == i)
			{
				printf("%d ", j);
				count = 1;
				break ;
			}
		}
		if (count == 0)
			printf("%d ", -1);
	}
	
	return (0);
}