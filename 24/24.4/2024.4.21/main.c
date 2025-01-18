#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
void func(int n)
{
	printf("n的值：%d\n",n);
	int count = 0;
	int start = clock();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			count++;
		}
	}

	for (int k = 0; k < 2*n; k++)
	{
		count++;
	}

	int x = 10;
	while (x--)
	{
		count++;
	}
	int end = clock();

	printf("count:%d\n",count);
	printf("所耗时间：%d\n",end-start);
}


int main()
{

	func(1);

	return 0;
}
