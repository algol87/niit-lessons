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
		switch (rand()%2)
		{
		case 0:
			ch=rand() % ('Z' - 'A' + 1) + 'A';
			break;
		case 1:
			ch = rand() % ('z' - 'a' + 1) + 'a';
			break;

		default:
			break;
		}
		//printf("%c", rand() % ('Z' - 'A' + 1) + 'A');  // rand from 0 to 32767
		putchar(ch);
		if (rand() % 10 > 7)
			putchar(' ');
		now = clock();
		while (clock() < now + CLOCKS_PER_SEC/10);
		
	}
		

	return 0;
}