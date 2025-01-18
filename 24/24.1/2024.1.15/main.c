#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int fun(int nums[], int numsSize)
{
	int num[100000] = { 0 };
	for (int i = 0; i < numsSize; i++)
	{
		num[i] = nums[i];
	}
		if (numsSize != 1)
		{
			for (int i = 0; i < numsSize - 1; i++)
			{
				for (int j = i; j < numsSize; j++)
				{
					if (nums[i] < nums[j])
					{
						int x = nums[i];
						nums[i] = nums[j];
						nums[j] = x;
					}
				}
			}
			if (nums[0] >= num[1] * 2)
			{
				for (int i = 0; i < numsSize; i++)
				{
					if (nums[0] == num[i])
					{
						return i;
					}
				}
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return -1;
		}
}
int main()

{
	int nums[3] = { 1,2,3 };
	int	numsSize = 3;
	int ret=fun(nums,numsSize);
	printf("%d\n", ret);
	return 0;
}
