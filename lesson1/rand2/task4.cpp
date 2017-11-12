#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
	int i;
	char ch;
	clock_t now;
	srand(time(0));
	for (;;)
	{
		while (1)
		{	
			for (i = 0; i < 10; i++)
				putchar(rand() % ('Z' - 'A' + 1) + 'A');
			if (rand() % 100>98)
			{
				putchar('\n');
				break;
			}
			putchar('\r');
			now = clock();
			while (clock() < now + 50);
			
		}
	}
	return 0;
}
