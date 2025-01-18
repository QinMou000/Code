#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void init(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		arr[i] = 0;
	}
}

void print(int arr[],int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[], int count)
{
	int backup[1000] = { 0 };
	for (int i = 0; i < count; i++)
	{
		backup[i] = arr[i];
	}
	for (int i = 0; i < count; i++)
	{
		arr[i] = backup[count - 1 - i];
	}
}

int main()
{
	int arr_c[10] = {0,1,2,3,4,5,6,7,8,9};
	
	print(arr_c, 10);

	init(arr_c, 10);

	print(arr_c, 10);
	int arr_b[11] = { 10,9,8,7,6,5,4,3,2,1,0 };

	reverse(arr_b, 11);

	print(arr_b, 11);

	return 0;
}