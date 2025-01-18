#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//
//int main() {
//	int n = 0, arr[50] = { 0 };
//	int x = 0;
//	while (scanf("%d\n", &n) != EOF) {//输入
//		for (int i = 0; i < n; i++)//输入
//		{
//			scanf("%d ", (arr + i));
//		}
//		scanf("%d", &x);//不想要的数
//		for (int i = 0; i < n; i++)
//		{
//			if (x != arr[i])//不等于x就输出
//				printf("%d ", arr[i]);
//		}
//	}
//	return 0;
//}

//int main()
//{
//	FILE* p1 = fopen("data", "r");
//	if (p1 == NULL)
//	{
//		perror("fopen");
//		return;
//	}
//	FILE* p2 = fopen("data_copy", "w");
//	if (p2 == NULL)
//	{
//		perror("fopen");
//		return;
//	}
//	int ch = 0;
//	while (ch = fgetc(p1) != EOF)
//	{
//		fputc(ch, p2);
//	}
//	fclose(p1);
//	fclose(p2);
//	p1 = NULL;
//	p2 = NULL;
//	return 0;
//}
//
//int main()
//{
//
//	char* cp1 = NULL;
//	char str = "hello world";
//	cp1 = &str;
//	/*********************/
//	const char* cp2 = "hello world";
//
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	char str1[] = "hello bit.";
//	char str2[] = "hello bit.";
//	const char* str3 = "hello bit.";
//	const char* str4 = "hello bit.";
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//	return 0;
//}
//
//#include <stdio.h>
//void test(int a[3][5], int r, int c)
//{
//	int i = 0;
//	int j = 0;
//
//	for(i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", a[i][j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6},{3,4,5,6,7} };
//	test(arr, 3, 5);
//	return 0;
//}

//#include <stdio.h>
//void test(int(*p)[5], int r, int c)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < r; i++)
//	{
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", *(*(p + i) + j));
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5}, {2,3,4,5,6},{3,4,5,6,7} };
//	test(arr, 3, 5);
//	return 0;
//}

//#include <stdio.h>
//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	printf("test:  %p\n", test);
//	printf("&test: %p\n", &test);
//	return 0;
//}

//(   *(   void (*)()    )   0)    ();

​
//int (*p)(int, int);
//
//​​
//void (   *signal   (   int, void(*)(int)    )    )    (int);
#include<stdlib.h>
#include<string.h>

int cmp(char x, char y)
{
	return x - y;
}

int main()
{
	char* str = (char*)malloc(1024);
	gets(str);
	int len = strlen(str);
	qsort(str, len, sizeof(char), (int)cmp);
	printf("%c\n", str[0]);

	return 0;
}
​