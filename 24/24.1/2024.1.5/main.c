#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()//实现三个数字从大到小排列
{
	int arr[3];
	int num;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d",&arr[i]);
	}
	for (int j = 0; j < 2; j++)
	{
		for (int i = j+1; i <= 2; i++)
		{
			if (arr[j] < arr[i])
			{
				num = arr[j];
				arr[j] = arr[i];
				arr[i] = num;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		printf("%d ",arr[i]);
	}

	return 0;
}

//int wq(int arr[3])//错误！！！！！！！！！！！！！
//{
//	int i = 0;
//	int num;
//	while (1)
//	{
//	if (arr[i] < arr[i+1])
//	{
//		if (i = 2)
//			break;
//		num = arr[i];
//		arr[i] = arr[i + 1];
//		arr[i + 1] = num;
//		i++;
//	}
//	}
//
//	return arr;
//}
//
//int main()
//{
//	int arr1[] = { 1,2,3 };
//	int arr2[3] = { 0 };
//	arr2[3] = wq(arr1);
//	for (int i = 0; i < 2; i++)
//	{
//		printf("%d ",arr2[i]);
//	}
//
//}