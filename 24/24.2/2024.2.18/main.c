#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{

}

int main()//ʲô����ϣ��ʲôgui��
{
	int nums[] = { 4,3,2,7,8,2,3,1 };
	int len = sizeof(nums) / sizeof(nums[0]);
	findDisappearedNumbers(nums, len, NULL);
	return 0;
}