#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#if 1
//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//Plan A
int fun(int* arr, int len)
{
	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		ret ^= arr[i];
	}
	for (int i = 0; i < len + 1; i++)
	{
		ret ^= i;
	}
	return ret;
}
//Plan b
int fun(int* arr, int len)
{
	int ret;
	for (int i = 0; i < len + 1; i++)
	{
		ret ^= i;
	}
	for (int i = 0; i < len; i++)
	{
		ret -= arr[i];
	}
	return ret;
}

int main()
{

	return 0;
}
#endif//gitee怎么传不上去了？