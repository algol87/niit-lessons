#include <stdio.h>
#define N 10

int search(int *arr, int size, int value,int start)
{
	
	for (int i = start; i < size; i++)
	{
		if (arr[i] == value)
			return i;	
	}
	return -1;

}

int main()
{
	int arr[N] = { 3, 4, 5, 6, 78, 45, 4, 5, 5, 4 };
	int start = 0,count=0;
	while ((start = search(arr, N, 52, start)) != -1)
	{
		printf("%d\n", start++);
		count++;
	}
		
	if (count==0)
	{
		printf("Not found\n");
	}

	return 0;
}