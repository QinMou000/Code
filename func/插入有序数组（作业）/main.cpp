#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a;
	int arr1[8] = { 1,2,4,4,5,10,12 };//定义数组
	int arr2[8] = { 1,2,4,4,5,10,12 };//备份数组
	int length = sizeof(arr1) / sizeof(arr1[0]);//计算数组长度
	//printf("%d ", length);

	for (int i = 0; i < length-1; i++)//输出初始数组
	{
		printf("%d ", arr1[i]);
	}

	printf("\n");
	scanf("%d",&a);//输入数字

	if (arr1[6] > a)
	{
		for (int i = 0; i < length; i++)//遍历arr1中各个元素
		{
			if (a < arr1[i])//比较：如果a<arr1[i]就将arr1[i]替换成a，后面的元素依次后移一位
			{
				arr1[i] = a;
				for (int j = i + 1; j < length; j++)
				{
					arr1[j] = arr2[i];//注意这里如果不用备份数组arr2的话，将会导致arr1[i]后面的元素全部等于a
					i++;
				}
			}
		}
	}

	else//将a赋值给arr1中最后一位元素
	{
		arr1[7] = a;
	}

	for (int i = 0; i < length; i++)//输出arr1中的所有元素
	{
		printf("%d ", arr1[i]);
	}

	printf("\n");
}