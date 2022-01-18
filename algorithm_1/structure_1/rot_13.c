#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char str[200];
	int len, i;

	fgets(str, sizeof(str), stdin);
	len = strlen(str) - 1;
	for (i = 0; i < len; i++)
	{
		if (islower(str[i]))
		{
			if (islower(str[i] + 13))
				str[i] += 13;
			else
				str[i] -= 13;
		}
		else if (isupper(str[i]))
		{
			if (isupper(str[i] + 13))
				str[i] += 13;
			else
				str[i] -= 13;
		}
	}
	for (i = 0; i < len; i++)
		printf("%c", str[i]);
	return (0);
}