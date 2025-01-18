#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#if 1
void print(int* a, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", a[i]);
	}
}

int cmp_by_int(const int* p1, const int* p2)
{
	return  *p2 - *p1;
}

void test1()
{
	int arr[] = { 2,8,6,4,9,3,1,5,7,0 };
	int len = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, len, sizeof(arr[0]), cmp_by_int);
	print(arr, len);
}
/*********************************************************************/
struct stu
{
	char name[20];
	int age;
};

int cmp_by_stu_name(const void * p1, const void * p2)
{
	return strcmp(((struct stu*)p1)->name, ((struct stu*)p2)->name);
}

int cmp_by_stu_age(const void* p1, const void* p2)
{
	return ((struct stu*)p1)->age - ((struct stu*)p2)->age;
}

void test2()
{
	struct stu arr[3] = { {"zhangsan",18},{"lisi",20},{"wangwu",19} };
	int len = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, len, sizeof(arr[0]), cmp_by_stu_name);

	for (int i = 0; i < len; i++)
		printf("%s ", arr[i].name);

	qsort(arr, len, sizeof(arr[0]), cmp_by_stu_age);

	for (int i = 0; i < len; i++)
		printf("%d ", arr[i].age);
}
/*********************************************************************/
void bubble_sort(int* a, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (a[j] > a[j+1])
			{
				a[j] = a[j] ^ a[j+1];
				a[j+1] = a[j] ^ a[j+1];
				a[j] = a[j] ^ a[j+1];
			}
		}
	}
}

void swap(char * p1,char * p2, size_t wide)
{
	for (int i = 0; i < wide; i++)//每个字节分开交换
	{
		char* tmp = p1;
		p1 = p2;
		p2 = tmp;
		p1++;
		p2++;
	}
}

void bubble_qsort(void * base,size_t len,size_t wide ,int (*cmp)(const void* ,const void* ))
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (cmp((char*)base + j * wide, (char*)base + (j + 1) * wide) > 0)//将第j和第j+1个元素的首地址传去cmp
			{
				swap((char*)base + j * wide, (char*)base + (j + 1) * wide, wide);//交换函数
			}
		}
	}
}
void test3()
{
	int arr[] = { 5,9,1,2,3,7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz,sizeof(arr[0]),cmp_by_int);
	print(arr, sz);
}
/*********************************************************************/
int main()
{
	test1();//对整型排序
	printf("\n");
	test2();//对结构体排序
	printf("\n");
	test3();//bubble_qsort模拟实现qsort

	return 0;
}
#endif



