#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//test.c
//�����ⲿ����
extern int Add(int x, int y);
//�����ⲿ��ȫ�ֱ���
extern int g_val;
int main()
{
	int a = 10;
	int b = 20;
	int sum = Add(a, b);
	printf("%d\n", sum);
	return 0;
}

int g_val = 2022;
int Add(int x, int y)
{
	return x + y;
}