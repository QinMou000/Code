#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
///*
//�������� n����˳���ӡ���� 1 ������ n λʮ��������
//�������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
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
						printf("%d��%d����%d���%d��\n", month, day, year, num);
						break;
					}
					else
					{
						printf("��������ȷ�ĺ���");
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
						printf("%d��%d����%d���%d��\n",month,day,year,num);
						break;
					}
				}
			}
			else
			{
				printf("��������ȷ���·�\n");
			}
		}
		else
		{
			printf("��������λ�������\n");
		}
	}
	return 0;
}