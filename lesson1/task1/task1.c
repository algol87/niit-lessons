#define _CRT_SECURE_NO_WARNINGS
#define SIZE 6
#include <stdio.h>
#include <string.h>


void clear(char name[])
{
	if (name[strlen(name) - 1] == '\n')
		name[strlen(name) - 1] = '\0';
}

void clear_stdin()
{
	int c;
	do{
		c = getchar();
	} while (c != '\n' && c != EOF);
}

int main()
{
	char name[SIZE];
	printf("What is your name?\n");
	fgets(name, SIZE, stdin);
	clear(name);
	//clear_stdin();
	fflush(stdin);		
	printf("Good name,%s!\n\n", name);
	printf("What is your name?\n");
	fgets(name, SIZE, stdin);
	//scanf("%s", name);
	printf("Good name,%s!\n\n", name);
	clear(name);
	return 0;

}