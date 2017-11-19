#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define OUT 0
#define N 256
#define LEN 5

//output words, which length of word = LEN

int main()
{
	char buf[N];
	char word[N];
	int flag = OUT;
	int i = 0,j=0,len=0;
	int count = 0;
	printf("Enter a line:\n");
	fgets(buf, N, stdin);
	buf[strlen(buf) - 1] = ' ';

	while (buf[i])
	{
		if (buf[i] != ' ' && flag == OUT)
		{
			len = 1;
			flag = IN;
			word[j++] = buf[i];
		}
		else if (buf[i] != ' ' && flag == IN)
		{
			word[j++] = buf[i];
			len++;
		}
		else if (buf[i] == ' ' && flag == IN)
		{
			flag = OUT;
			if (len == LEN)
			{
				word[j] = '\0';
				printf("%s ", word);
			}
			len = j = 0;
		}
		i++;
	}
	printf("\n");

	return 0;
}