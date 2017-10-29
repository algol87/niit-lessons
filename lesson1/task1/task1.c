#define _CRT_SECURE_NO_WARNINGS
#define SIZE 6
#include <stdio.h>
#include <string.h>


void clear(char name[])
{
	if (name[strlen(name) - 1] == '\n')
		name[strlen(name) - 1] = '\0';
}

int main()
{
	char name[SIZE];
	printf("What is your name?\n");
	fgets(name, SIZE, stdin);
	clear(name);
	//scanf("%s", name);
	printf("Good name,%s!\n\n", name);
	return 0;

}