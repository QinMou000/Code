#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#if 0
int fun(int a)
{
	int tmp = 0;
	while (a)
	{
		tmp += a % 10;
		a /= 10;
	}
	if (tmp < 10)
		return tmp;
	else
		return fun(tmp);
}

int main()
{
	int n = 0;
	scanf("%d",&n);
	printf("%d\n",fun(n));
	return 0;
}
#endif

int fun(int L,int R)
{
	int count = 0;
	for (int i = L; i <= R; i++)
	{
		int tmp = i;
		while (tmp)
		{
			if (tmp % 10 == 2)
				count++;
			tmp /= 10;
		}
	}
	return count;
}

int main()
{
	int L, R;
	scanf("%d %d", &L, &R);
	printf("%d\n",fun(L,R));
	return 0;
}