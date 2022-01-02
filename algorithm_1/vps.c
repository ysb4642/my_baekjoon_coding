#include <stdio.h>
#include <string.h>

int main(void)
{
	int n, i, j, cnt, len;
	char str[51];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		cnt = 0;
		scanf("%s", str);
		len = strlen(str);
		for (j = 0; j < len; j++)
		{
			if (cnt < 0)
				break ;
			if (str[j] == '(')
				cnt++;
			else if (str[j] == ')')
				cnt--;
		}
		if (cnt == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return (0);
}
