#include <stdio.h>

int main(void)
{
	int n, grade, i, max;
	float avr, sum;
	scanf("%d", &n);
	float arr[n];

	max = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &grade);
		if (max < grade)
			max = grade;
		arr[i] = grade;
	}
	for (i = 0; i < n; i++)
		arr[i] = arr[i] / max * 100;
	sum = 0;
	for (i = 0; i < n; i++)
		sum += arr[i];
	avr = sum / n;
	printf("%f", avr);
	return (0);
}