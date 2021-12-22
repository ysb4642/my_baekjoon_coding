#include <stdio.h>


int main(void)
{
	int n;
	
	scanf("%d", &n);
	int movie = 665;
	int cnt = 0;
	int temp;
	while (cnt != n)
	{
		movie++;
		temp = movie;
		while (temp > 665)
		{
			if (temp % 1000 == 666)
			{
				cnt++;
				break;
			}
			else
				temp /= 10;
		}
	}
	printf("%d\n", movie);
	return (0);
}