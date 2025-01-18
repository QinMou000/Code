#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

//int main()
//{
//	int* p = malloc(1);
//	p[0] = 10;
//	p[1] = 20;
//	p[2] = 30;
//	printf("%d ",*p);
//	return 0;
//}

//int main()
//{
//	int* p = NULL;
//	p = malloc(3 * sizeof(int));
//	if (p == NULL)
//		perror("malloc");
//	else
//	{
//		//......
//	}
//	return 0;
//}

//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//
//void test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf("%s",str);
//}
//
//int main()
//{
//	test();
//	return 0;
//}

#include<stdlib.h>

//int main()
//{
//	int** p = (int**)malloc(3 * sizeof(int*));
//	for (int i = 0; i < 3; i++)
//	{
//		p[i] = (int*)malloc(5 * sizeof(int));
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			printf("%p\n",&p[i][j]);
//		}
//	}
//
//	return 0;
//}

//int* getConcatenation(int* nums, int numsSize, int* returnSize)
//{
//	*returnSize = (2 * numsSize);
//	int* arr = (int*)malloc(sizeof(int)*2*numsSize);
//	for (int i = 0; i < numsSize; i++)
//	{
//		arr[i] = arr[i + numsSize] = nums[i];
//	}
//	return arr;
//}

//int* getConcatenation(int* nums, int numsSize, int* returnSize)
//{
//	int* arr = (int*)malloc(sizeof(int) * (numsSize * 2));
//
//	for (int i = 0; i < numsSize; i++) 
//		arr[i] = arr[i + numsSize] = nums[i];
//
//	*returnSize = (numsSize * 2);
//
//	return arr;
//}

//int main()
//{
//	int arr[] = { 1,2,3 }; 
//	int size = sizeof(arr) / sizeof(arr[0]);
//	int returnsize = 2 * size;
//	int* p = getConcatenation(arr, size,&returnsize);
//	return 0;
//}

//int main()
//{
//	int* p = NULL;
//	p = calloc(3, 4);
//	if (p == NULL)
//		perror("calloc");
//	else
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%d ",*(p+j));
//		}
//	}
//	return 0;
//}
#include<string.h>

//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//main()
//{
//	Test();
//	return 0;
//}

//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf("%s",str);
//}
//
//int main()
//{
//	Test();
//
//	return 0;
//}

//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	if (str != NULL)
	{
		strcpy(str, "world");
		printf(str);
	}
}

int main()
{
	Test();
	return 0;
}