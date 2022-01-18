#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int k, i, n, cnt = 0;
	char command[6];
	int *data;

	scanf("%d", &k);
	data = (int *)malloc(sizeof(int) * k);
	for (i = 0; i < k; i++)
	{
		scanf("%s", command);
		if (!strcmp(command, "push"))
		{
			scanf("%d", &n);
			data[cnt++] = n;
		}
		else if (!strcmp(command, "pop"))
		{
			if (cnt == 0)
				printf("-1\n");
			else
			{
				printf("%d\n", data[cnt - 1]);
				cnt--;
			}
		}
		else if (!strcmp(command, "size"))
			printf("%d\n", cnt);
		else if (!strcmp(command, "top"))
		{
			if (cnt == 0)
				printf("-1\n");
			else
				printf("%d\n", data[cnt - 1]);
		}
		else if (!strcmp(command, "empty"))
		{
			if (cnt == 0)
				printf("1\n");
			else
				printf("0\n");
		}

	}
	free(data);
	data = NULL;
	return (0);
}