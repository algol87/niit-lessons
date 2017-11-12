#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 1000
#define N 26

int main()
{
	int i,j;
	
	srand(time(0));
	char buf[SIZE];
	int count[N] = { 0 };
	int max = 0;

	for (i=0;i<SIZE-1;i++)
	{
		buf[i] = rand() % ('Z' - 'A' + 1) + 'A';
	}
	buf[SIZE - 1] = '\0';
	puts(buf);
	
	i = 0;
		while (buf[i] != '\0')
		{
			count[buf[i] - 'A']++;
			i++;
		}
		
		for (i = 0; i < N; i++)
		{
			if (count[i]>max)
				max = count[i];
			printf("%c-%d\n", i + 'A', count[i]);
		}

		for (i = 0; i < N; i++)
		{
			if (count[i] == max)
				printf("Max %c-%d\n", i + 'A', count[i]);
		}
		
		
	

	return 0;
}