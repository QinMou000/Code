#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	int a = 2;
//	int b = 3;
//	printf("%d %d\n",a,b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("%d %d\n", a, b);
//	return 0;
//}

//int fun(int n)
//{
//	int count = 0;
//	for (int i = 0; i < 32; i++)
//	{
//		if (n>>i & 1 == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fun(n);
//	printf("%d\n",ret);
//	return 0;
//}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int count = 0;
	int c = a ^ b;
	while (c)
	{
		c = c & (c - 1);
		count++;
	}
	printf("%d\n",count);
	return 0;
}