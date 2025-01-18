#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>
bool zhishu(int n)
{
	int flag = 1;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
			flag = 0;
	}
	return flag;
}
int main()
{
	int count = 0;
	for (int i = 1; i < 2021; i++)
	{
		for (int j = 1; j < 2021; j++)
		{
			if (i == 1 || j == 1)
			{
				count++;
				continue;
			}
			if (zhishu(i) && zhishu(j))
			{
				count++;
				continue;
			}
			if ((zhishu(i) && j % i != 0) || (zhishu(j) && (i % i != 0)))
			{
				count++;
				continue;
			}
		}
	}
	return 0;
}
#if 0
int main()
{
	int n = 1;
	int count = 0;
	for (n = 1; n <= 2020; n++)
	{
		int tmp = n;
		while (tmp)
		{
			if (tmp % 10 == 2)
			{
				count++;
			}
			tmp /= 10;
		}
	}
	printf("%d\n",count);
	return 0;
}
#endif