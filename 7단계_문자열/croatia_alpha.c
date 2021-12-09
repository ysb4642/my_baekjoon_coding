#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[100];
	int len, i, count;

	scanf("%s", str);
	len = strlen(str);
	count = len;
	for (i = 0; i < len; i++)
	{
		if (str[i] == '=')
		{
			if (str[i - 1] == 'c' || str[i - 1] == 's' || str[i - 1] == 'z')
			{
				if (str[i - 1] == 'z')
				{
					if (str[i - 2] == 'd')
						count--;
				}
				count--;
			}
		}
		else if (str[i] == '-')
		{
			if (str[i - 1] == 'c' || str[i - 1] == 'd')
				count--;
		}
		else if (str[i] == 'j')
		{
			if (str[i - 1] == 'l' || str[i - 1] == 'n')
				count--;
		}
	}
	printf("%d\n", count);
}
