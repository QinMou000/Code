#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>

#if 0
int x = 1;
int fun(int k)//有时候还是不要着了递归的魔了qwq
{
	int sum = 0;
	while (k>x)
	{
		sum += x * x;
		k -= x;
		x++;
	}
	sum += k * x;
	return sum;
}

int fun(int k)//为什么我写不出递归啊！！！！！！！！！！！！！
{
	int sum = 0;
	if (k - x < 0)
	{
		x++;
		sum += k * x;
	}
	else
	{	
		x++;
		sum += fun(k - x) + x * x;
	}
	return sum;
}


int main()
{
	int k = 0;
	scanf("%d",&k);
	int ret = fun(k);
	printf("%d\n", ret);
}
#endif

//bool isPalindrome(int x)
//{
//	long tmp = 0;
//	long num = x;
//	if (x < 0)
//		return false;
//	while (num)
//	{
//		tmp = tmp * 10 + num % 10;
//		num /= 10;
//	}
//	return x == tmp;
//}
//
//bool isPalindrome(int x)
//{
//	int tmp = 0;
//	int num = x;
//	if (x < 0)
//	{
//		return false;
//	}
//	while (num)
//	{
//		tmp = tmp * 10 + num % 10;
//		num /= 10;
//	}
//	if (tmp == x)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	
//	printf("%d", isPalindrome(121));
//	return 0;
//}

#if 0
void fun(int n)
{
	for (int i = 1; i < n + 1; i++)
	{
		int tmp = 0;
		int num = i;
		while (num)
		{
			tmp = tmp * 10 + num % 10;
			num /= 10;
		}
		if (tmp == i)
		{
			printf("%d\n", i);
		}
	}
}

int main()
{
	int n = 0;
	scanf("%d",&n);
	fun(n);
	return 0;
}
#endif