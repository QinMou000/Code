#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void find_num(int arr[], int len, int* pnum1, int* pnum2)
{
	int tmp = 0;
	//将整个数组异或起来
	for (int i = 0; i < len; i++)
	{
		tmp ^= arr[i];
	}
	//找到tmp中二进制为1的某一位k
	int k = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((tmp >> i) & 1 != 0)
		{
			k = i;
			break;
		}
	}
	//遍历数组 把每个数据 第k位是1的分到一个组，异或，两值存到pnum1，2
	*pnum1 = *pnum2 = 0;
	for (int i = 0; i < len; i++)
	{
		if (((arr[i] >> k) & 1) != 0)
		{
			//第k位是1
			*pnum1 ^= arr[i];
		}
		else
		{
			//第k位是0
			*pnum2 ^= arr[i];
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int num1 = 0;
	int num2 = 0;
	find_num(arr, len, &num1, &num2);
	printf("%d %d",num1,num2);
	return 0;
}