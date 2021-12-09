#include <stdio.h>

int main(void)
{
	int n, i, j, cnt;

	scanf("%d", &n);
	cnt = 1;
	if (n == 1)
	{
		printf("%d", cnt);
		return (0);
	}
	i = 2;
	j = 5;
	while(1)
	{	
		cnt++;
		if (i <= n && n <= i + j)
		{
			printf("%d", cnt);
			break ;
		}
		i = i + j + 1;
		j += 6;
	}
	return (0);
}