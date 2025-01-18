#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//int* sumZero(int n, int* returnSize)
//{
//	int* arr = (int*)calloc(n , (sizeof(int)));
//	int left = 0;
//	int right = n - 1;
//	int i = 1;
//	while (left <= right)
//	{
//		arr[left] = i;
//		arr[right] = -i;
//		if (left == right)
//		{
//			arr[left] = 0;
//			break;
//		}
//		left++;
//		right--;
//		i++;
//	}
//	*returnSize = n;
//	return arr;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	int* returnsize = &n;
//	int* ans = sumZero(n, returnsize);
//	for (int i = 0; i < *returnsize; i++)
//	{
//		printf("%d\n",ans[i]);
//	}
//	return 0;
//}
//
//int mul(int x, int y)
//{
//	int ans = 0;
//	for (int i = 0; i < y; i++)
//	{
//		ans += x;
//	}
//	return ans;
//}
//
//int jueduizhi(int n)
//{
//	if (n > 0)
//		return n;
//	return -n;
//}
//
//int divide(int a, int b)
//{
//	if ((a < 0 && b < 0) || (a > 0 && b > 0))
//	{
//		for (int i = 0; i < jueduizhi(a); i++)
//		{
//			if (mul(i, jueduizhi(b)) >= jueduizhi(a) - 1 && mul(i, jueduizhi(b)) < jueduizhi(a) + 1)
//			{
//				return i;
//			}
//		}
//	}
//	else
//	{
//		for (int i = 0; i < a; i--)
//		{
//			if (mul(i, b) >= a - 1 && mul(i, b) < a + 1)
//			{
//				return i;
//			}
//		}
//	}
//	return INT_MAX;
//}
//
//int main()
//{
//	printf("%d\n",divide(7,-3));
//	return 0;
//}
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "");
	wchar_t x = '¡ñ';
	wprintf("%lc",x);
	return 0;
}
