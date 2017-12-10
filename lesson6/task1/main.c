#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define N 25
#define M 80

int compareStr(const void *a, const void *b)
{
	if (strlen(*(char**)a) > strlen(*(char**)b))
		return 1;
	else
		return -1;
}

void linesort2(char *str[], int size)
{
	char* temp;
	for (int i = 0; i < size;i++)
		for (int j = size - 1; j>i;j--)
			if (strlen(str[i]) > strlen(str[j]))
			{
				temp = str[j];
				str[j] = str[i];
				str[i] = temp;
			}		
}

void linesort(char *str[], int size)
{
	qsort(str, size, sizeof(char*), compareStr);
}

void printLines(const char *str[], int size)
{
	for (int i = 0; i < size; i++)
		puts(str[i]);
}

int main()
{
	char text[N][M];
	char*pstr[N];
	int count = 0;
	while (count < N && *fgets(text[count], M, stdin) != '\n')
		pstr[count] = text[count++];
	//linesort(pstr, count);
	linesort2(pstr, count);
	printLines(pstr, count);

	return 0;
}