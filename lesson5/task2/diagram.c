#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define fopen_s




int main()
{
	FILE *fp,*inp;
	int N = 100, ch;
	double x, y;
	fp = fopen("sin.xls", "wt");
	inp = fopen("diagram.c", "rt");

	if (fp == NULL || inp == NULL)
	{
		puts("File error!");
		return 1;
	}

	for (int i = -100; i < N; i++)
	{
		x = 2.0 * M_PI *i / N;
		y = sin(x);
		fprintf(fp, "%f\t%f\n", x, y);
		fprintf(stdout, "%f\t%f\n", x, y);

	}

	while ((ch = fgetc(inp)) != EOF)
		putc(ch, stdout);
	fclose(fp);
	fclose(inp);
	

	return 0;
}