#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000

int main(void)
{
	int n;
	char res[SIZE * 2];
	int stack[SIZE];
	int top = -1;
	int *arr;

	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int num = 1;
	int idx = 0, res_idx = 0;
	while(1)
	{
		// 스택 상단에 있는 수가 목표 수 보다 낮은 경우 push
		if (top == -1 || stack[top] < arr[idx])
		{
			stack[++top] = num++;
			res[res_idx++] = '+';
		}
		// 스택 상단 부분의 수가 목표수와 같은 경우 pop
		else if (stack[top] == arr[idx])
		{
			top--;
			res[res_idx++] = '-';
			idx++;
		}
		// 스택의 상단부분의 수가 목표 수보다 높은 경우 (수열 만들 수 없음)
		else
		{
			printf("NO\n");
			return (0);
		}
		if (res_idx == n * 2)
			break ;
	}
	for (int i = 0; i < res_idx; i++)
		printf("%c\n", res[i]);
	free(arr);
	arr = NULL;
	return (0);
}