#define _CRT_SECURE_NO_WARNINGS
#include "country.h"
#include <stdio.h>

int main()
{
	FILE *fp;
	struct COUNTRY *head = 0;

	fp = fopen("countries.csv", "rt");
	if (!fp)
	{
		perror("File:");
		return 1;
	}
	head = mklist(fp);
	printf("%x\n", head);
	if (head == NULL)
	{
		puts("Data error!");
		return 2;
	}
	fclose(fp);
	return 0;
}