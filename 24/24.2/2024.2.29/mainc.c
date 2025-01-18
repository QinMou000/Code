#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int fun(int age)
{
	return age * 3156;
}

int main()
{
	int n;
	scanf("%d", &n);
	long long int ret = fun(n);
	printf("%d0000\n", ret);
	return 0;
}

#if 0
int fun(int n)
{
	if (n > 0)
		return fun(n - 1)*1<<1;
	else
		return 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	int ret = fun(n);
	printf("%d\n", ret);
	return 0;
}

int main()
{
	int N = 0;
	int X = 0;
	scanf("%d%d",&X,&N);
	N %= 7;
	if ((N + X) % 7 == 0)
		printf("%d", (N + X) % 7+7);
	else
		printf("%d\n",(N+X)%7);

	return 0;
}
#endif