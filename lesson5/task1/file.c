#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1024

int countLines(FILE *fp)
{
	char buf[N];
	int count = 0;
	while (fgets(buf, N, fp) != NULL)
		count++;
	return count;
}

int main()
{
	FILE *fp;
	int count = 0;
	char buf[N];
	int choice;
	srand(time(0));
	fp = fopen("wisdom.txt", "rt");
	if (fp == NULL)
	{
		puts("I cant open file");
		return 1;
	}
	count = countLines(fp);
	rewind(fp);
	rand();
	choice = rand() % count + 1;
	while (choice)
	{
		fgets(buf, N, fp);
		choice--;
	}
	puts(buf);
	return 0;
}