#include <stdio.h>

#define small(a, b) a < b ? a : b

int main(void)
{
	int n, m, cntB, cntW, min = 80;
	int i, j;
	char chess[50][50];

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", &chess[i]);
	for (i = 0; i < n - 7; i++)
	{
		for (j = 0; j < m - 7; j++)
		{
			cntB = 0;
			cntW = 0;
			for (int a = i; a < i + 8; a++)
			{
				for (int b = j; b < j + 8; b++)
				{
					if ((a + b) % 2 == 0)
					{
						if (chess[a][b] == 'B')
							cntW++;
						else
							cntB++;
					}
					else
					{
						if (chess[a][b] == 'B')
							cntB++;
						else
							cntW++;
					}
				}
			}
			min = small(min, cntB);
			min = small(min, cntW);
		}
	}
	printf("%d\n", min);
	return (0);
}