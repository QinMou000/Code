#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

bool leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int year;
	printf("������Ҫ�жϵ���ݣ�");
	scanf("%d", &year);
	int ret=leap_year(year);
	printf("%d\n", ret);
	return 0;
}