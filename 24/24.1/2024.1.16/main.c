#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

int main()
{
	char s[1000];
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i; j < len; j++)
		{
			if (s[i] > s[j])
			{
				int x = s[i];
				s[i] = s[j];
				s[j] = x;
			}
		}
	}
	puts(s);
	return 0;
}


int pivotIndex(int* nums, int numsSize) 
{
	int flag = 0;
	int ret = 0;
	for (int i = 0; i < numsSize; i++)//����ָ��������
	{
		int sum1 = 0;
		int sum2 = 0;
		for (int x = 0; x < i; x++)
		{
			sum1 += nums[x];
		}
		for (int y = numsSize-1; y >i; y--)
		{
			sum2 += nums[y];
		}
		//�ֱ����i�±��������ߵĺ�
		if (sum1 == sum2)
		{
			flag = 1;//�ж�
			ret = i;//�±����
			break;
		}
	}
	if (flag == 1)
	{
		return ret;
	}
	else
	{
		return-1;
	}
}
int main()
{

	int arr[] = { -1,-1,0,0,-1,-1 };

	int root=pivotIndex(arr, 6);
	printf("%d\n",root);
	return 0;
}