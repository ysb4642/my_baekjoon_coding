#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[100];
	int alpha[26] = {0, };
	int i, strLen;

	scanf("%s", str);
	strLen = strlen(str);
	for (i = 0; i < strLen; i++)
		alpha[str[i] - 'a']++;
	for (i = 0; i < 26; i++)
		printf("%d ", alpha[i]);
	return (0);
}