#include <stdio.h>
#include <string.h>

int main(void)
{
	int alpha[26];
	char str[100];
	int i, strLen;
	
	scanf("%s", str);
	strLen = strlen(str);

	memset(alpha, -1, sizeof(int) * 26);

	for (i = 0; i < strLen; i++)
	{
		if (alpha[str[i] - 'a'] == -1)
			alpha[str[i] - 'a'] = i;
	}
	for (i = 0; i < 26; i++)
		printf("%d ", alpha[i]);
	return (0);
}