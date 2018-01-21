#include "zoo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	TAnimal *head = create();
	addTail(head);
	addTail(head);
	addTail(head);
	addTail(head);
	addTail(head);
	printList(head);

	return 0;
}