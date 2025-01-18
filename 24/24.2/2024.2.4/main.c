#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#if 1
int year_m_day(int y,int m)
{
	int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
	{
		if (m == 2)
		{
			return arr[m] + 1;
		}
		else
		{
			return arr[2];
		}

	}
	else
	{
		return arr[m];
	}
}

int main()
{
	int ret = year_m_day(2024,2);
	printf("%d\n", ret);

	return 0;
}
#endif