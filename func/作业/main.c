#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#if 0

int cmp(char* x, char* y)
{
	return *y - *x;
}

int main()
{
	char str[1024];
	scanf("%s",str);
	int len = strlen(str);
	int(*p)(char*, char*) = &cmp;
	qsort(str, len, 1, p);
	char s = *str;
	printf("%c\n", s);

	return 0;
}

int Two_NumGcd(int a, int b)
{
		if (b == 0)
			return a;
		return Two_NumGcd(b, a % b);
}

int gcd(int x, int y, int z)
{
	return Two_NumGcd(Two_NumGcd(x, y), z);
}

int main()
{
	int a, b, c;
	scanf("%d %d %d",&a,&b,&c);
	int num = gcd(a,b,c);
	printf("%d\n",num);
	return 0;
}

#endif