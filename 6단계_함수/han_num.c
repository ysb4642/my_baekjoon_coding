#include <stdio.h>

int cal(int n)
{
	int i, num, a, b, c;

	num = n;
	c = num % 10;
	num /= 10;
	b = num % 10;
	num /= 10;
	a = num % 10;

	if ((b - a) == (c - b))
		return (1);
	else
		return (0);
}

void	han_num(int n)
{
	int i, count;
	if (0 < n && n < 100)
	{
		count = n;
		printf("%d", count);
	}
	else if (99 < n && n < 1000)
	{	
		count = 99;
		for (i = 100; i <= n; i++)
		{
			if (cal(i))
				count++;
		}
		printf("%d", count);
	}
	else
		han_num(999);
}

int	main(void)
{
	int n;

	scanf("%d", &n);
	han_num(n);
	return (0);
}

/*어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. */