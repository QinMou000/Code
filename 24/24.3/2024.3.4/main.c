#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int singleNumber1(int* nums, int numsSize)
//{
//	int root = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		root ^= nums[i];
//	}
//	return root;
//}
//
//int singleNumber2(int* nums, int numsSize)
//{
//	int sum1 = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		sum1 += nums[i];
//	}
//	for (int i = 0; i < numsSize; i++)
//	{
//		for (int j = i+1; j < numsSize; j++)
//		{
//			if (nums[i] = nums[j])
//			{
//				for (int n = j; n < numsSize; n++)
//				{
//					nums[n] = nums[n + 1];
//				}
//				numsSize--;
//			}
//		}
//	}
//	int sum2 = 0;
//	for (int i = 0; i < numsSize; i++)
//	{	
//		sum2 += nums[i];
//	}
//	return (sum2 * 3 - sum1)/2;
//
//}
//
//int singleNumber2(int* nums, int numsSize) {
//	int ans = 0;
//	for (int i = 0; i < 32; ++i) {
//		int total = 0;
//		for (int j = 0; j < numsSize; ++j) {
//			total += ((nums[j] >> i) & 1);
//		}
//		if (total % 3) {
//			ans |= (1u << i);
//		}
//	}
//	return ans;
//}

//int* singleNumber3(int* nums, int numsSize, int* returnSize)
//{
//	int i;
//	int sum = 0;
//	for (i = 0; i < numsSize; i++)
//	{
//		sum ^= nums[i];
//	} //先找到两个数互相异或的结果
//	int pos;
//	for (i = 0; i < 32; i++)
//	{
//		if (sum & 1 << i)
//		{
//			pos = i;
//			break;
//		}
//	} //再找到有分歧的一位。在这一位上，两个数一定是一个1一个0
//	//int arr[2] = { 0 };
//	int* arr = calloc(2, sizeof(int));
//	for (i = 0; i < numsSize; i++)//从分歧那一位入手，分为俩类
//	{
//		if (nums[i] & 1 << pos)
//		{
//			arr[0] ^= nums[i]; //这一位是1的，放在数1里
//		}
//		else
//		{
//			arr[1] ^= nums[i]; //这一位是0的，放在数2里
//		}
//	}
//	return arr;
//}

int main()
{
	char str[] = "abcde";
	printf("%zd", &str + 1);
	return 0;
}