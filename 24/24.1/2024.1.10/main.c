#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//void Nicomachus(int n)
//{
//	int num = n * n * n;
//	if()
//}
//
//int main()//验证尼科彻斯定理
//{
//	int n;
//	scanf("%d",&n);
//	Nicomachus(n);
//	return 0;
//}

int main()
/*
	等差数列 2，5，8，11，14。。。。
	（从 2 开始的 3 为公差的等差数列）
	输出求等差数列前n项和
*/
{
	int n;
	scanf("%d",&n);
	float ret = 2*n + n * (n - 1) * 1.5;
	printf("%.0f\n",ret);
	return 0;
}