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
//	} //���ҵ��������������Ľ��
//	int pos;
//	for (i = 0; i < 32; i++)
//	{
//		if (sum & 1 << i)
//		{
//			pos = i;
//			break;
//		}
//	} //���ҵ��з����һλ������һλ�ϣ�������һ����һ��1һ��0
//	//int arr[2] = { 0 };
//	int* arr = calloc(2, sizeof(int));
//	for (i = 0; i < numsSize; i++)//�ӷ�����һλ���֣���Ϊ����
//	{
//		if (nums[i] & 1 << pos)
//		{
//			arr[0] ^= nums[i]; //��һλ��1�ģ�������1��
//		}
//		else
//		{
//			arr[1] ^= nums[i]; //��һλ��0�ģ�������2��
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