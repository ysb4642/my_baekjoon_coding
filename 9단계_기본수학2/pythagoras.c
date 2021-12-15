#include <stdio.h>

int main(void)
{
	int a, b, c;

	while(1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 || b == 0 || c == 0)
			break ;
		a *= a;
		b *= b;
		c *= c;
		if (a == b + c || b == a + c || c == a + b)
			printf("right\n");
		else
			printf("wrong\n");
	}
	return (0);
}

/*
int main(void)
{
	int a, b, c, max;

	while(1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 || b == 0 || c == 0)
			break ;
		max = a;
		if (max < b)
			max = b;
		if (max < c)
			max = c;
		if (max == a)
		{
			if (a * a == ((b * b) + (c * c)))
				printf("right\n");
			else
				printf("wrong\n");
		}
		else if (max == b)
		{
			if (b * b == ((a * a) + (c * c)))
				printf("right\n");
			else
				printf("wrong\n");
		}
		else
		{
			if (c * c == ((b * b) + (a * a)))
				printf("right\n");
			else
				printf("wrong\n");
		}
	}
	return (0);
}*/