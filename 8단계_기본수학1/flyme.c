#include <stdio.h>
#include <math.h>

int main(void)
{
	int T, i, x, y, n, k;

	scanf("%d", &T);
	for (i = 0; i < T; i++)
	{
		scanf("%d %d", &x, &y);

		n = sqrt(y - x);
		if (n * n == y - x)
			k = n * 2 - 1;
		else
		{
			if ((n * n) < (y - x) && (y - x) <= (n * n + n))
				k = n * 2;
			else
				k = n * 2 + 1;
		}
		printf("%d\n", k);
	}
	return (0);
}