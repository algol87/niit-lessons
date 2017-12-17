#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define M 5


int main()
{
	int arr[N][M] = { { 1, 5, 6,5 ,5}, { 2, 4, 6,4 ,9}, { 2, 4, 6,3,1 } };
	int arrSum[N][M] = { 0 };
	int res[N][M] = { 0 };
	int i = 0;
	int j = 0;
	

	arrSum[0][0] = arr[0][0];

		for (j = 1; j < M; j++)
		{
			arrSum[0][j] = arrSum[0][j-1] + arr[0][j];
			arrSum[j][0] = arrSum[j-1][0] + arr[j][0];
		}

		for (i = 1; i < N; i++)
		{
			for (j = 1; j < M; j++)
			{
				if (arrSum[i - 1][j] + arr[i][j]>arrSum[i][j - 1] + arr[i][j])
					arrSum[i][j] = arrSum[i - 1][j] + arr[i][j];
				else
					arrSum[i][j] = arrSum[i][j - 1] + arr[i][j];
			
			}
			
		}





		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
				printf("%02d  ", arr[i][j]);
			printf("\n");
		}

		printf("\n");
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
				printf("%02d  ", arrSum[i][j]);
			printf("\n");
		}

	return 0;
}