#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define PTR_T int*//ֻ���滻���ݣ�����Ϊ�������ʹ����µ����֣�����
/*
�����ptr p1 p2//p1p2����ָ�����
��PTR_T p3 p4//p3p4ֻ��p3��ָ�������p4�����ͱ���
��PTR_T�����룺int *p3,p4;
��ptr�����룺int* p3;  int* p4;

*/

typedef int* ptr;//���¶���������͵�д��
typedef int(*parr_t)[5];//pf_t�����µ�����pf_t����int(*)[5]
typedef void(*pf_t)(int);//pf_t���� void(*)(int)

int add(int a, int b)
{
	return a + b;
}

char* test(char c, char n)
{
	//hahahahahhahahaha
}

int main()
{
	//printf("%p\n",&add);
	//printf("%p\n", add);
	
	//int (*pf)(int, int) = &add;
	//int ret = pf(1, 2);
	//printf("%d\n", ret);
	
	//char* (*p)(char, char) = &test;

	(*(void(*)())0)();
	void (*signal(int, void(*)(int)))(int);

	return 0;
}

#if 0
void print(int(*p)[5], int x, int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d ", *(*(p + i) + j));
		}
		printf("\n");
	} 
}

int main()
{
	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
	print(arr,3,5);
	return 0;
}

int main()
{
	int a = 10;
	int* pa = &a;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*p)[10] = &arr;
	for (int i = 0; i < 10; i++)
	{
		printf("%d ",(*(*p)+i));//*p==arr,but������̫����
	}

	return 0;
}
#endif