#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//������ʱ�临�Ӷȣ���֤���һ��gapΪ1
		for (int i = 0; i < n - gap; i++)//һ������ֿ���
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)//������ҲҪ��һ��
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];//��λ��
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;//����
		}
	}
}

int main()
{ 
	int a[] = { 2,3,6,8,7,5,9,1,4 };
	ShellSort(a, sizeof(a) / sizeof(int));
	return 0;
}