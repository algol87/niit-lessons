#define _CRT_SECURE_NO_WARNINGS
#include "countries.h"
#include <stdio.h>

int main()
{
	FILE *fp;
	int number = 0;
	struct COUNTRY *arr = 0;

	fp = fopen("countries.csv", "rt");
	if (!fp)
	{
		perror("File:");
		return 1;
	}
	number = mkArray(&arr, fp);
	printf("%d\n", number);
	if (number == 0)
	{
		puts("Data error!");
		return 2;
	}
	fclose(fp);
	return 0;
}