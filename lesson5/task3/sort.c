#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int compare(const void *a, const void *b)
{ 
	if(*(int*)a > *(int*)b) 
		return 1; 
	else
		return -1; 
} 

int compareStr(const void *a, const void *b)
{
	if (strlen(*(char**)a) > strlen(*(char**)b))
		return -1; 
	else
		return 1;
}

int main() { 
	int arr[10]={34,89,56,21,67,34,78,84,90,3},i; 
	qsort(arr,10,sizeof(int),compare); 
	for(i=0;i<10;i++)
		printf("%d ",arr[i]);
	printf("\n ");

	char* arrS[3] = { "dddd","ddddddd","dss" };
	qsort(arrS, 3, sizeof(char*), compareStr);
	for (i = 0; i<3; i++)
		printf("%s ", arrS[i]);

	return 0; 
}
