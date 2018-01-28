
#include <stdio.h>
#include <time.h>
#define N 8

char arr[N][N] = { 0 };

int checkPosition(int i, int j)
{
	int k = 1;
	while (i-k >=0 && j-k>=0)
	{
		if (arr[i-k][j-k] != 0)
			return 1;
		k++;
	}
	k = 1;
	while (i-k >= 0)
	{
		if (arr[i-k][j] != 0)
			return 1;
		k++;
	}
	k = 1;
	while (i-k >= 0 && j+k < N)
	{
		if (arr[i-k][j+k] != 0)
			return 1;
		k++;
	}
	return 0;
}

void printSolution()
{
	int i = 0, j = 0;
	while (i < N)
	{
		printf("\n");
		while (j < N)
		{
			printf("%c ", arr[i][j]);
			j++;
		}
		i++;
	}
	//clock_t now = clock();
	//while (clock() < now + 100);
	//system("cls");
}

void placeQueen(int i)
{
	static int count = 0;
	if (i == N)
	{
		printSolution();
		return;
	}
	else
	{
		count++;
		for (int j = 0; j < N; j++)
		{
			
			if (!checkPosition(i, j))
			{
				arr[i][j] = '*';
				placeQueen(i + 1);
			}	
			/*if (i < count)
			{
				arr[i][j] = '\0';
			}*/
		}
		
	}
}




int main()
{
	placeQueen(0);
	//printSolution();
	return 0;
}