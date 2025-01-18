#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#if 0
//void fun(int * a,int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		for (int j = i; j < num; j++)
//		{
//			if (a[i] < a[j])
//			{
//				a[i] = a[i] ^ a[j];
//				a[i] = a[i] ^ a[j];
//				a[j] = a[i] ^ a[j];
//			}
//		}
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ",a[i]);
//	}
//}

int main()
{
	int num = 0;
	scanf("%d", &num);
	int a[50] = { 0 };
	int i = 0;
	while (scanf("%d", &a[i]) != EOF)
	{
		i++;
	}
	//for (int i = 0; getchar != '\n'; i++)
	//{
	//	scanf("%d", &a[i]);
	//}
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (a[i] < a[j])
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
#endif