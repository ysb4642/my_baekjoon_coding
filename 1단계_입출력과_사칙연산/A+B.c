#include <stdio.h>

int main(void)
{
	int A, B;

	scanf("%d %d", &A, &B);
	if (A <= 0 || B >= 10)
	{
		printf("잘못된 입력입니다.\n");
		return (0);
	}
	printf("%d\n", A + B);
	return (0);
}