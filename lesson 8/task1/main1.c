#include <math.h>
#include <stdio.h>

//2^0+2^1+2^2+...+2^63=2^64-1

typedef unsigned long long ull;

ull iter(ull n, ull sum)
{
	if (n == 64)
		return sum;
	else
		return iter(n + 1, sum + (ull)pow(2.0, n));
}

unsigned int iterInt(unsigned int n, unsigned int sum)
{
	if (n == 32)
		return sum;
	else
		return iterInt(n + 1, sum + (unsigned int)pow(2.0, n));
}

ull chessNumber()
{
	return iter(0, 0);
}

unsigned int chessNumber2()
{
	return iterInt(0, 0);
}

int main()
{
	printf("%llu\n", chessNumber());
	printf("%u\n", chessNumber2()+1);
}
