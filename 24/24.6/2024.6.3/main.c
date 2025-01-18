#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define   N   3
#define   Y(n)  ((N+1)*n)

//void f(int a, int b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int x = 1;
//	int y = 3;
//	int z = 2;
//	if (x > y)
//		f(x, y);
//	else
//		if (y > z)
//			f(x, z);
//		else
//			f(x, z);
//	printf("%d %d %d \n",x,y,z);
//	return 0;
//}

int main()
{
	int z = 2 * (N + Y(5 + 1));


	return 0;
}