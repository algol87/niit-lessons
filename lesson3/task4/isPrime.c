#include <stdio.h>
#define N 10
#include <time.h>

int isPrime(int value)
{
	for (int n = 2; n*n <= value;n++)
	if (value%n == 0)
		return 0;
	return 1;
}

void getPrimen(int n)
{
	int i = 2;
	int count = 0;
	while (1)
	{
		if (isPrime(i) == 1)
		{
			count++;
			printf("%d\n", i);
		}
			
		if (count == n)
			break;
		i++;
	}
	return 0;
}

int main()
{
	clock_t start, finish;
	/*for (int i = 2; i < 20; i++)
		printf("%d-%d\n", i, isPrime(i));*/
	start = clock();
	getPrimen(300000); 
	finish = clock();
	printf("%.2f\n", (float)(finish - start) / CLOCKS_PER_SEC);
	return 0;
	

}