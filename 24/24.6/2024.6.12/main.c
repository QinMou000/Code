#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//决定了时间复杂度，保证最后一次gap为1
		for (int i = 0; i < n - gap; i++)//一个个组分开排
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)//等于零也要排一次
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];//换位子
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;//插入
		}
	}
}

int main()
{ 
	int a[] = { 2,3,6,8,7,5,9,1,4 };
	ShellSort(a, sizeof(a) / sizeof(int));
	return 0;
}