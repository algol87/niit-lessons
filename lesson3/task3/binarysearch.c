#include <stdio.h>
#define N 10

int binarySearch(int *arr, int size, int value)
{
	int left = 0;
	int right = size - 1;
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (value < arr[middle])
			right = middle - 1;
		else if (value>arr[middle])
			left = middle + 1;
		else
			return middle;
	}
	return -1;
}

int main()
{
	int arr[N] = { 3, 4, 5, 6,33, 45, 49, 59, 65, 84 };
	int max, min;
	

	printf("%d\n", binarySearch(arr,N,84));

	return 0;
}