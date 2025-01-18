#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int fun(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return fun(n - 1) + fun(n - 2);
//	}
//}

//int fun(int n)//  1 1 2 3 5 8 13 21 34 55 89 
//{
//	int sum = 1;
//	int num = 1;
//	int ret = 1;
//	if (n <= 2)
//	{	
//		return 1;
//	}
//	else
//	{
//		for (int i = 0; i < n-2; i++)
//		{
//			sum = ret + num;
//			num = ret;
//			ret = sum;
//		}
//		return sum;
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret = fun(n);
//	printf("%d\n",ret);
//	return 0;
//}

//int fun(int n, int k)
//{
//	if (k > 1)
//	{
//		return n * fun(n, k - 1);
//	}
//	else
//	{
//		return n;
//	}
//
//}
//int main()
//{
//	int n, k;
//	scanf("%d,%d", &n,&k);
//	int ret = fun(n,k);
//	printf("%d\n",ret);
//	return 0;
//}

//int DigitSum(int n)
//{
//	int sum = 0;
//	if (n > 9) 
//	{
//		sum += n % 10;
//		return sum+DigitSum(n / 10);
//	}
//	else
//	{
//		return sum + n;
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int ret=DigitSum(n);
//	printf("%d\n",ret);
//	return 0;
//}

//int fun(int n)
//{
//	if (n > 1)
//	{
//		return n * fun(n - 1);
//	}
//	else
//	{
//		return 1;
//	}
//}

//int fun(int n)
//{
//	int factor = 1;
//	for (int i = 1; i <= n; i++)
//	{
//		factor *= i;
//	}
//	return factor;
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int ret = fun(n);
//	printf("%d\n",ret);
//	return 0;
//}

//void fun(int n)
//{
//	if (n > 9)
//	{
//		fun(n / 10);
//		printf("%d ", n % 10);
//	}
//	else
//	{
//		printf("%d ", n);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	fun(n);
//	return 0;
//}

//int main()
//{
//	int x = 2;
//	int y = 3;
//	printf("%d %d\n", x, y);
//	int medium = x;
//	x = y;
//	y = medium;
//	printf("%d %d\n", x, y);
//	return 0;
//}

//int main()
//{
//	int x = 2;
//	int y = 3;
//	printf("%d %d\n", x, y);
//	x = x + y;
//	y = x - y;
//	x = x - y;
//	printf("%d %d\n", x, y);
//	return 0;
//}

int main()
{
	int x = 2;
	int y = 3;
	printf("%d %d\n", x, y);
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	printf("%d %d\n", x, y);
	return 0;
}