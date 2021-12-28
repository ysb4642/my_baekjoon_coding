#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int age;
	char name[101];
} Info;

int compare(const void *first, const void *second)
{
	Info *a = (Info *)first;
	Info *b = (Info *)second;

	if (a->age < b->age)
		return (-1);
	else if (a->age > b->age)
		return (1);
	return (0);
}

int main(void)
{
	int n, i;
	Info *card;

	scanf("%d", &n);
	card = (Info *)malloc(sizeof(Info) * n);
	for (i = 0; i < n; i++)
		scanf("%d %s", &card[i].age, card[i].name);
	qsort(card, n, sizeof(card[0]), compare);
	for (i = 0; i < n; i++)
		printf("%d %s\n", card[i].age, card[i].name);
	free(card);
	card = NULL;
	return (0);
}
