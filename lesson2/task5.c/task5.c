#include "task5.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "task5.h"


extern int matr[N][M];

void gen()
{
	int i, j;
	for (i = 0; i < N;i++)
	for (j = 0; j < M; j++)
		matr[i][j] = rand() % 100;

}

void print()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
	for (j = 0; j < M; j++)
	
		printf("%02d ", matr[i][j]);
	putchar('\n');
	}
		

}