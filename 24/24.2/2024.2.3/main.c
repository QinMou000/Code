#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define PTR_T int*//只是替换内容，不是为变量类型创建新的名字！！！
/*
下面的ptr p1 p2//p1p2都是指针变量
而PTR_T p3 p4//p3p4只有p3是指针变量，p4是整型变量
（PTR_T）编译：int *p3,p4;
（ptr）编译：int* p3;  int* p4;

*/

typedef int* ptr;//重新定义各种类型的写法
typedef int(*parr_t)[5];//pf_t就是新的名字pf_t就是int(*)[5]
typedef void(*pf_t)(int);//pf_t就是 void(*)(int)

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
		printf("%d ",(*(*p)+i));//*p==arr,but这样用太冗余
	}

	return 0;
}
#endif