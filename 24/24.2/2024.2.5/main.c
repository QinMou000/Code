#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int fun(int n, int m)
{
	if (m == 1)
	{
		return n;
	}
	else
	{
		return n * fun(n - 1, m - 1);
	}
}

//int funs(int n)
//{
//	return n == 1 ? n : funs(n - 1) * n;//직그！！！！！！！！！！！！！！！！！！
//}
//
//int fun(int m,int n)
//{
//	return funs(n) / funs(n - m);
//}

int main()
{
	int m = 0;
	int n = 0;
	scanf("%d %d", &n, &m);
	int ret = fun(n, m);
	printf("%d\n", ret);
	return 0;
}

#if 0
void fun(int n)
{
	if (n > 0)
	{
		printf("%d ",n%10);
		fun(n/10);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	fun(n);
	return 0;
}

int fun(int n)
{
	if (n > 1)
	{
		return fun(n - 1) + n;
	}
	else
	{
		return 1;
	}
}

int main()
{
	int n = 0;
	scanf("%d",&n);
	int ret = fun(n);
	printf("%d\n", ret);
	return 0;
}

int funs(int n)
{
	return n == 1 ? n : funs(n - 1) * n;//직그！！！！！！！！！！！！！！！！！！
}

int main()
{
		int n = 0;
		scanf("%d",&n);
		int ret = funs(n);
		printf("%d\n", ret);
		return 0;
}
#endif