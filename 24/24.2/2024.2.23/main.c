#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#if 1
//����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
//Plan A
int fun(int* arr, int len)
{
	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		ret ^= arr[i];
	}
	for (int i = 0; i < len + 1; i++)
	{
		ret ^= i;
	}
	return ret;
}
//Plan b
int fun(int* arr, int len)
{
	int ret;
	for (int i = 0; i < len + 1; i++)
	{
		ret ^= i;
	}
	for (int i = 0; i < len; i++)
	{
		ret -= arr[i];
	}
	return ret;
}

int main()
{

	return 0;
}
#endif//gitee��ô������ȥ�ˣ�