#include "zoo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void chomp(char *buf)
{
	buf[strlen(buf) - 1] = 0;
}

TAnimal* create()
{
	char tmp[64];
	TAnimal *item = (TAnimal*)malloc(sizeof(TAnimal));
	printf("Enter type: ");
	fgets(item->type, 64, stdin);
	chomp(item->type);
	printf("Enter name: ");
	fgets(item->name, 64, stdin);
	chomp(item->name);
	printf("Enter age: ");
	fgets(tmp, 64, stdin);
	item->age = atoi(tmp);
	printf("Danger (0/1)? ");
	fgets(tmp, 64, stdin);
	item->danger = atoi(tmp);
	item->next = NULL;
	return item;
}
void addTail(TAnimal *head)
{
	while (head->next)
		head = head->next;
	head->next = create();
}
void printList(TAnimal *head)
{
	putchar('\n');
	while (head)
	{
		printf("%15s %15s %2d %s\n",
			head->type,
			head->name,
			head->age,
			(head->danger) ? "Danger" : "Not danger");
		head = head->next;
	}
}
int searchAnimal(TAnimal *head, char* type)
{
	while (head)
	{
		if (strstr(head->type, type))
			return 1;
		head = head->next;
	}
	return 0;
}