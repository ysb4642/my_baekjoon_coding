#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr[1000000];
	char res[1000000];
	int num = 0, i = 0, j = 0, len;

	scanf("%s", arr);
	len = strlen(arr);
	if (len % 3 == 0)
	{
		while (i < len)
		{
			num = (arr[i] - '0') * 4 + (arr[i + 1] - '0') * 2 + (arr[i + 2] - '0');
			res[j++] = num + '0';
			i += 3;
		}
	}
	else if (len % 3 == 1)
	{
		res[j++] = arr[i++];
		while (i < len)
		{
			num = (arr[i] - '0') * 4 + (arr[i + 1] - '0') * 2 + (arr[i + 2] - '0');
			res[j++] = num + '0';
			i += 3;
		}
	}
	else
	{
		num = (arr[i] - '0') * 2 + arr[i + 1] - '0';
		res[j++] = num + '0';
		i += 2;
		while (i < len)
		{
			num = (arr[i] - '0') * 4 + (arr[i + 1] - '0') * 2 + (arr[i + 2] - '0');
			res[j++] = num + '0';
			i += 3;
		}
	}
	res[j] = '\0';
	printf("%s", res);
	return (0);
}