#include <stdio.h>

int main(void)
{
	int A, B, V, day;
	scanf("%d %d %d", &A, &B, &V);

	day = (V - B) / (A - B);
	if ((V - B) % (A - B) == 0)
		printf("%d", day);
	else
		printf("%d", day + 1);
	return (0);
}