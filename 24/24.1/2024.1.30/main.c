#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//void Bubbling_sorting(int arr[], int sz)
//{
//	int i = 0;
//	//趟数
//	for (i = 0; i < sz - 1; i++)
//	{
//		//假设已经有序了
//		int flag = 1;
//		//一趟排序的过程
//		int j = 0;
//		for (j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}

void Bubbling_sorting(int* arr, int len)
{
	for (int i = 0; i < len-1; i++)
	{
		int flag = 1;
		for (int j = 0; j < len-i-1; j++)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				int tmp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}

int main()
{
	int arr[] = {1,2,3,4,3,4,5,6,5,6,7,8};
	int len = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");

	Bubbling_sorting(arr, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");

	return 0;
}
#if 0
void print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", *(arr + i));
	}
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int len = sizeof(arr)/sizeof(arr[0]);
	print(arr,len);
	return 0;
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("%p\n", arr);
	printf("%p\n", &arr);

	return 0;
}

#endif