#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//void swap(int* nums, int left, int right)
//{
//	while (left < right)
//	{
//		int tmp = nums[left];
//		nums[left] = nums[right];
//		nums[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//	int x = k % numsSize;
//	swap(nums, 0, numsSize - 1);
//	swap(nums, 0, x - 1);
//	swap(nums, x, numsSize - 1);
//}
//
//int main()
//{
//	int arr[7] = {1,2,3,4,5,6,7};
//	rotate(arr,7,3);
//	return 0;
//

//int cmp(const void* x, const void* y)
//{
//	return *(int*)y - *(int*)x;
//}
//
//int* targetIndices(int* nums, int numsSize, int target, int* returnSize)
//{
//	int j = 0;
//	qsort(nums, numsSize, 4, cmp);
//	int count = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] == target)
//			count++;
//	}
//	*returnSize = count;
//	int* arr = (int*)malloc(sizeof(int) * (*returnSize));
//	if (arr == NULL)
//		exit(1);
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] == target)
//		{
//			arr[j] = i;
//			j++;
//		}
//	}
//	return arr;
//}

int* targetIndices(int* nums, int numsSize, int target, int* returnSize)
{
	int count = 0;
	int sign = 0;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == target)
			count++;
		else
			sign++;
	}
	*returnSize = count;
	int* arr = (int*)malloc(sizeof(int) * (*returnSize));
	if (arr == NULL)
		exit(1);
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == target)
		{
			arr[i] = sign++;
		}
	}
	return arr;
}

int main()
{
	int arr[] = { 1,2,5,2,3 };
	int* returnSize = 1;
	int* ret = targetIndices(arr, 5, 2, returnSize);
	return 0;
}