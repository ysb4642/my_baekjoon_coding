#include <stdio.h>

int main(void)
{
	int N, a;

	scanf ("%d", &N);
	a = 0;
	while(1)
	{
		if (N % 5 == 0)
		{
			a += N / 5;
			printf("%d", a);
			break ;
		}
		else
		{
			N -= 3;
			a++;
		}
		if (N < 0)
		{
			printf("-1");
			break ;
		}
	}
	return (0);
}