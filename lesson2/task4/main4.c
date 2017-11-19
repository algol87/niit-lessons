#include <stdio.h>

//string to integer

int str2int(char *buf)
{
	unsigned int value = 0;
	int i = 0;
	while (buf[i])
	{
		value = value * 10 + buf[i] - '0';
		i++;
		if (i == 9)
			break;

	}
	return value;
}


int main()
{
	char buf[128] = "45677777";
	int digit;
	printf("%d\n", str2int(buf));
	return 0;
}