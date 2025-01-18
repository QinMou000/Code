#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//get_num_of_k(int nums[], int numsLen, int k)
//{
//	int num = 0;
//	for (int i = 0; i < numsLen; i++)
//	{
//		if (nums[i] == k)
//		{
//			num++;
//		}
//	}
//	return num;
//}

int convertInteger(int A, int B)
{
	int c = A ^ B;
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (c == 1)
		{
			count++;
		}
		c >>= 1;
	}
	return count;
}

int main()
{
	int a = 1;
	int b = 0;
	int num=convertInteger(a,b);
	printf("%d\n",num);
	return 0;
}