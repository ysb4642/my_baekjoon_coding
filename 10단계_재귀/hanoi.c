#include <stdio.h>
#include <math.h>

void	HanoiTowerMove(int num, int a, int b, int c)
{
	if (num == 1)
		printf("%d %d\n", a, c);
	else
	{
		HanoiTowerMove(num - 1, a, c, b);
		printf("%d %d\n", a, c);
		HanoiTowerMove(num - 1, b, a, c);
	}
}

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d\n", (int)pow(2, n) - 1);
	HanoiTowerMove(n, 1, 2, 3);
	return (0);
}
/*
void	HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)
		printf("원반 1을 %c에서 %c로 이동\n", from, to);
	else
	{
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반 %d를 %c에서 %c로 이동\n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int	main(void)
{
	HanoiTowerMove(3, 'A', 'B', 'C');
	return (0);
}*/