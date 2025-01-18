#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
///*
//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
//比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
//*/
//{
//	int num;
//	int x = 1;
//	scanf("%d",&num);
//	for (int i = 0; i < num; i++)
//	{
//		x = x * 10;
//	}
//	for (int i = 1;1; i++)
//	{
//		printf("%d ",i);
//		if (x - 1 == i)
//		{
//			break;
//		}
//	}
//	next:
//	return 0;
//}

int main()
{
	int year, month, day;
	int num = 0;
	int arr1[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
	int arr2[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	scanf("%d %d %d",&year,&month,&day);
	while (1)
	{
		if (year > 1000 && year < 9999)
		{
			if (month > 0 && month <= 12)
			{
				if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				{
					if (day > 0 && day < arr1[month])
					{
						for (int i = 0; i < month; i++)
						{
							num += arr1[i];
						}
						for (int j = 0; j < day; j++)
						{
							++num;
						}
						printf("%d月%d日是%d年的%d天\n", month, day, year, num);
						break;
					}
					else
					{
						printf("请输入正确的号数");
					}
				}
				else
				{
					if (day > 0 && day < arr2[month])
					{
						for (int i = 0; i < month; i++)
						{
							num += arr2[i];
						}
						for (int j = 0; j < day; j++)
						{
							++num;
						}
						printf("%d月%d日是%d年的%d天\n",month,day,year,num);
						break;
					}
				}
			}
			else
			{
				printf("请输入正确的月份\n");
			}
		}
		else
		{
			printf("请输入四位数的年份\n");
		}
	}
	return 0;
}