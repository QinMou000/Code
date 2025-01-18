#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//int main()
//{
//	int n = 3;
//	char arr['10'] = "ahfsj";
//	int len = sizeof(arr);
//	for (int i = 0; i < len; i++)
//	{
//		printf("%c\n",&arr[i]);
//	}
//	char str[];
//
//	return 0;
//}

//int main()
//{
//	char str[1000] = { '0' };
//	scanf("%s", &str);
//	unsigned int len = strlen(str);
//	int num = 0;
//	for (int i = 0; i < len-1; i++)
//	{
//		for (int j = i; j < len; j++)
//		{
//			if (str[i] > str[j])
//			{
//				char ch = str[i];
//				str[i] = str[j];
//				str[j] = ch;
//			}
//		}
//	}
//	for (int i = 0; i < len+1 ; i++)
//	{
//		if (str[i] != str[i + 1])
//		{
//			num++;
//		}
//	}
//	printf("%d\n", num);
//	return 0;
//}

//int majorityElement(int* nums, int numsSize)
//{
//	int num = numsSize / 2;
//	int ret;
//	int max = 0;
//	for (int i = 0; i < numsSize; i++)
//	{
//		ret = 0;
//		for (int j = i; j < numsSize; j++)
//		{
//			if (nums[i] == nums[j])
//			{
//				ret++;
//			}
//		}
//		if (ret > max)
//		{
//			max = ret;
//		}
//		if (max > num)
//		{
//			return nums[i];
//		}
//	}
//	return 0;
//}

int majorityElement(int* nums, int numsSize)//Ä¦¶ûÍ¶Æ±·¨
{
	int num = nums[0];
	int count = 1;
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == num)
		{
			count++;
		}
		else
		{
			count--;
			if (count == 0)
			{
				num = nums[i];
			}
		}
	}
	return num;
}
int main()
{
	int arr[] = { 6,5,5 };
	int root=majorityElement(arr,3);
	printf("%d\n", root);
	return 0;
}