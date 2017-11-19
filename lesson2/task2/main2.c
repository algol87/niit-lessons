#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define OUT 0

//amount of words and output every word

int main()
{
	char buf[512];
	int flag = OUT;
	int i = 0;
	int count = 0;
	printf("Enter a line:\n");
	fgets(buf, 512, stdin);
	buf[strlen(buf) - 1] = '\0';

	while (buf[i])
	{
		if (buf[i] != ' ' && flag == OUT)
		{
			count++;
			flag = IN;
			putchar(buf[i]);
		}
		else if (buf[i] != ' ' && flag == IN)
		{
			putchar(buf[i]);
		}
		else if (buf[i] == ' ' && flag == IN)
		{
			flag = OUT;
			putchar('\n');
		}
		i++;
	}
	putchar('\n');
	printf("%d words\n", count);
	return 0;
}