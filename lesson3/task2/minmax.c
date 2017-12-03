#include <stdio.h>
#define N 10

int search(int *arr, int size, int value, int start)
{

	for (int i = start; i < size; i++)
	{
		if (arr[i] == value)
			return i;
	}
	return -1;

}

int getMax(int *arr, int size)
{
	int max = arr[0];
	for (int i = 1; i < size;i++)
		if (arr[i]>max)
			max = arr[i];
	return max;
}

void getMaxMin(int *arr, int size,int *max,int *min)
{

	*max =*min= arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i]>*max)
			*max = arr[i];
		if (arr[i]<*min)
			*min = arr[i];
	}
	
}

int main()
{
	int arr[N] = { 3, 4, 5, 6, 78, 45, 4, 5, 5, 4 };
	int max, min;
	getMaxMin(arr, N, &max, &min);

	printf("Max=%d Min=%d\n", max,min);

	return 0;
}