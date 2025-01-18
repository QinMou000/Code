#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

bool Determine_prime(int Num)
{
	int flag = 0;
	for (int i = 2; i < Num; i++)
	{
		if (Num % i == 0)
		{
			return  true;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		return false;
	}
}

int main()
{
	int num;
	printf("请输入要判断的数：");
	next:
	scanf("%d", &num);
	if (num > 1)
	{
		if (Determine_prime(num))
		{
			printf("这个数不是素数！\n");
		}
		else
		{
			printf("这个数是素数！\n");
		}

	}
	else
	{
		printf("输入错误！请重新输入！\n");
		goto next;
	}

	
	return 0;
}