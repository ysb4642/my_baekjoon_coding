#include <stdio.h>
#include <string.h>

int main(void)
{
	char arr[340000];
	char first[10][4] = {"", "1", "10", "11", "100", "101", "110", "111"};
	char table[10][4] = {"000", "001", "010", "011", "100", "101", "110", "111"};
	int len, i;

	scanf("%s", arr);
	len = strlen(arr);
	if (arr[0] == '0')
	{
		printf("0");
		return (0);
	}
	printf("%s", first[arr[0] - '0']);
	for (i = 1; i < len; i++)
		printf("%s", table[arr[i] - '0']);
	return (0);
}