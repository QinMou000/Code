#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	int n1 = m - 1;
//	int n2 = n - 1;
//	int n3 = m + n - 1;
//	while (n1 >= 0 && n2 >= 0)
//	{
//		if (nums1[n1] <= nums2[n2])
//		{
//			nums1[n3--] = nums2[n2--];
//		}
//		else
//		{
//			nums1[n3--] = nums1[n1--];
//		}
//	}
//	if (n2 >= 0)
//	{
//		while (n2 >= 0)
//		{
//			nums1[n3--] = nums2[n2--];
//		}
//	}
//}

int removeElement(int* nums, int numsSize, int val)
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] == val)
		{
			src++;
		}
		else
		{
			nums[dst] = nums[src];
			dst++;
			src++;
		}
	}
	return dst;
}


int main()
{

	return 0;
}