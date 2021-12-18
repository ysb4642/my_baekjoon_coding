#include <stdio.h>

void stars(int i, int j, int n)
{
	if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
		printf(" ");
	else
	{
		if (n / 3 == 0)
			printf("*");
		else
			stars(i, j, n / 3);
	}
}

int main(void)
{
	int n, i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			stars(i, j, n);
		printf("\n");
	}
	return (0);
}