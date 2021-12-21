#include <stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);
	int temp = n;
	int digit = 0;
	while (temp)
	{
		temp /= 10;
		digit++;
	}
	// 분해합은 최소 n - 9*digit 자릿수부터 시작
	int begin = n - 9 * digit;
	for (int i = begin; i <= n; i++)
	{
		int sum = i;
		temp = i;
		while (temp)
		{
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n)
		{
			printf("%d", i);
			n = 0;
			break ;
		}
	}
	if (n != 0)
		printf("0");
	return (0);
}