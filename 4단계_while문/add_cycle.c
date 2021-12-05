#include <stdio.h>

int main(void)
{
	int a, temp, count;
	int n1, n2, new_num;

	count = 0;
	scanf("%d", &a);
	temp = a;
	while (1)
	{
		n1 = temp / 10;
		n2 = temp % 10;
		new_num = (n2 * 10) + ((n1 + n2) % 10);
		if (new_num == a)
		{
			count++;
			break ;
		}
		else
			count++;
		temp = new_num;
	}
	printf("%d", count);
	return (0);
}