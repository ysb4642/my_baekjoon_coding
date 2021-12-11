#include <stdio.h>
#include <string.h>

void reverse(char arr[])
{
	int len, i;
	char temp;

	len = strlen(arr);
	for (i = 0; i < len / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[len - 1 - i];
		arr[len - 1 - i] = temp;
	}
}

int main(void)
{
	char a[10001] = {0, };
	char b[10001] = {0, };
	char res[10002] = {0, };
	int d; // 자릿수 올림
	int len, i, sum;

	scanf("%s %s", a, b);
	reverse(a);
	reverse(b);
	len = strlen(a) >strlen(b) ? strlen(a) : strlen(b);
	d = 0;
	for (i = 0; i < len; i++)
	{
		sum = (a[i] - 48) + (b[i] - 48) + d;
		if (sum < 0)
			sum += 48;		// 자릿수가 다를경우에 sum은 -48을 한번더 계산되기 때문에 (둘중 하나는 null이므로)
		if (sum > 9)
			d = 1;
		else
			d = 0;
		res[i] = sum % 10 + 48;
	}
	if (d == 1)
		res[len] = '1';
	reverse(res);
	printf("%s", res);
	return (0);
}