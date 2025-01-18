#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//int  main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    printf("&arr[0] =   %p\n", &arr[0]);
//    printf("&arr[0]+1 = %p\n", &arr[0] + 1);
//    printf("arr =       %p\n", arr);
//    printf("arr+1 =     %p\n", arr + 1);
//    printf("&arr =      %p\n", &arr);
//    printf("&arr+1 =    %p\n", &arr + 1);
//	return 0;
//}
//void test1(int arr[])//参数写成数组形式，本质也是指针
//{
//    int sz1 = sizeof(arr) / sizeof(arr[0]);
//    printf("sz1 = %d\n", sz1);//结果为1
//}
//void test2(int* arr)//参数写成指针形式
//{
//    int sz2 = sizeof(arr) / sizeof(arr[0]);
//    printf("sz2 = %d\n", sz2);//计算⼀个指针变量的⼤⼩
//}
//int main()
//{
//    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    printf("sz = %d\n", sz);//结果为10
//    test1(arr);
//    test2(arr);
//    return 0;
//}

int main()
{
	int a = 10;
	int* pa = &a;
	int** ppa = &pa;
	printf("%d", **ppa);
	return 0;
}