#include <stdio.h>

int main (void)
{
	int C, i, n, sum, count;
	float avr, val;

	scanf("%d", &C);
	while (C--)
	{
		scanf("%d", &n);
		int arr[n];
		sum = 0;
		count = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		avr = (float)sum / n;
		for (i = 0; i < n; i++)
		{
			if (avr < arr[i])
				count++;
		}
		val = (float)count / n * 100;
		printf("%.3f%%\n", val);
	}
	return (0);
}
