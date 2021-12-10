#include <stdio.h>

int main(void)
{
	int x, i, j, k;

	scanf("%d", &x);
	if (x == 1)
	{
		printf("1/1");
		return (0);
	}
	i = 2;
	j = 1;
	while (1)
	{
		if (i <= x && x <= i + j )
		{
			k = x - i;
			if (j % 2 != 0)
				printf("%d/%d", 1 + k, j + 1 - k);
			else
				printf("%d/%d", j + 1 - k, 1 + k);
			break ;
		}
		j++;
		i = i + j;
	}
	return (0);
}