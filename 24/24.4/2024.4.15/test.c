#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

//bool isprimes(int n)
//{
//	if (n == 2)
//		return 1;
//	for (int i = 2; i < n ; i++)
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int countPrimes(int n)
//{
//	int count = 0;
//	for (int j = n-1; j > 1; j--)
//	{
//		if (isprimes(j))
//			count++;
//	}
//	return count;
//}
//
//int main()
//{
//	printf("%d\n", countPrimes(49979));
//	return 0;
//}


//bool isprimes(int n)
//{
//	if (n == 2)
//		return 1;
//	for (int i = 2; i < n ; i++)
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//bool isUgly(int n)
//{
//	if (n <= 0)
//		return false;
//	if (n == 1)
//		return true;
//	bool flag = true;
//	for (int i = 2; i <= n; i++)
//	{
//		if (i == 2 || i == 3 || i == 5)
//		{
//			if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
//			{
//				flag = true;
//			}
//			i++;
//			continue;
//		}
//		if (n % i == 0)
//		{
//			flag = false;
//		}
//	}
//	if (isprimes(n) && flag == true)
//		flag = false;
//	return flag;
//}

bool isUgly(int n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;
	if (n % 2 == 0)
		return isUgly(n / 2);
	if (n % 3 == 0)
		return isUgly(n / 3);
	if (n % 5 == 0)
		return isUgly(n / 5);
}

//bool isUgly(int n) {
//    if (n <= 0) {
//        return false;
//    }
//    if (n == 1) {
//        return true;
//    }
//    while (n % 2 == 0) {
//        n /= 2;
//    }
//    while (n % 3 == 0) {
//        n /= 3;
//    }
//    while (n % 5 == 0) {
//        n /= 5;
//    }
//    return n == 1;
//}

int main()
{
	printf("%d\n", isUgly(2));
	return 0;
}