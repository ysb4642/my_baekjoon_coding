#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1000000];
	int i, cnt, len;

	scanf("%[^\n]", str); // 엔터가 나올때까지 문자열로 받는다는 말이다( 공백도 포함 ), gets로 받으면 됨. ex) gets(str);
	i = 0;
	cnt = 0;
	len = strlen(str);

	if (len == 1)
	{
		if (str[i] == ' ')
		{
			printf("0");
			return (0);
		}
	}

	for (i = 1; i < len - 1; i++)
	{
		if (str[i] == ' ')
			cnt++;
	}

	printf("%d", cnt + 1);
	return (0);
}