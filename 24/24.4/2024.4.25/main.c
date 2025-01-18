#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int isodd(int n)
{
	if (n % 2 == 1)
		return 1;
	else
		return 0;
}

int numberOfSteps(int num)
{
	int ans = 0;
	while (num)
	{
		if (isodd(num))
		{
			num -= 1;
			ans++;
		}
		else
		{
			num /= 2;
			ans++;
		}
	}
	return ans;
}

int main()
{


	return 0;
}