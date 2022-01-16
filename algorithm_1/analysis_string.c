#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char str[200];
	int i, strLen, lower, upper, digit, space, sum;

	while(fgets(str, 200, stdin) != NULL)
	{
		strLen = strlen(str) - 1;
		lower = 0;
		upper = 0;
		digit = 0;
		space = 0;
		for (i = 0; i < strLen; i++)
		{
			if (islower(str[i]))
				lower++;
			else if (isupper(str[i]))
				upper++;
			else if (isdigit(str[i]))
				digit++;
			else if (isspace(str[i]))
				space++;
		}
		printf("%d %d %d %d\n", lower, upper, digit, space);
	}
	return (0);
}