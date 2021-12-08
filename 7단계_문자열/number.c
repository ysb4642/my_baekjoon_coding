#include <stdio.h>
#include <stdlib.h>

char	*trans(int a)
{
	int n, i;
	char c;
	char *str;

	str = (char *)malloc(sizeof(char) * 3 + 1);

	for (i = 0; i< 3; i++)
	{
		n = a % 10;
		c = n + '0';
		str[i] = c;
		a /= 10;
	}
	return(str);
	free(str);
}

int main(void)
{
	char *s1;
	char *s2;
	int a, b;
	char temp;


	s1 = (char *)malloc(sizeof(char) * 3 + 1);
	s2 = (char *)malloc(sizeof(char) * 3 + 1);
	scanf("%d %d", &a, &b);
	
	s1 = trans(a);
	s2 = trans(b);
	
	a = atoi(s1);
	b = atoi(s2);
	
	if (a > b)
		printf("%d\n", a);
	else
		printf("%d\n", b);
	free(s1);
	free(s2);
	return (0);
}