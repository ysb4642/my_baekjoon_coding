#include <stdio.h>

int main(void)
{
	int a, b;

	scanf("%d %d", &a, &b);
	if (a <= 0 || b >= 10)
	{
		printf("잘못된 입력입니다.\n");
		return (0);
	}
	printf("%d\n", a - b);
	return (0);
}