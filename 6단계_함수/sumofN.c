long long sum(int *a, int n)
{
	int i;
	long long sum;

	sum = 0;
	for (i = 0; i < n; i++)
		sum += a[i];
	return (sum);
}
