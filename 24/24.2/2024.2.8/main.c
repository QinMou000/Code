#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int Findnum(int ar[], int n)
{
	int tem[100] = { 0 };
	for (int i = 0; i < n; i++)
	{
		tem[ar[i]]++;
	}
	for (int i = 0; i < n; ++i)
	{
		if (tem[i] == 1)
			return i;
	}
}

//int Findnum(int ar[], int n)
//{ 
//	int i, j;
//	for (i = 0; i < n; ++i)
//	{
//		for (j = 0; j < n; ++j)
//		{
//			if (i == j)
//				continue;
//			if (ar[i] == ar[j])
//				break;
//		}
//		if (j == n)
//			break;
//	}
//	return ar[i];
//}

int main()
{
/*
一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
编写一个函数找出这两个只出现一次的数字。
*/

	int ar[5] = { 1, 2, 3, 3, 1 };
	int n = sizeof(ar) / sizeof(ar[0]);
	int res = Findnum(ar, n);
	printf("res = %d\n", res);
	return 0;
}