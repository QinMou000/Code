#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>

//int main()
//{
//	int i, j;
//	for (i = 10000; i < 99999; i++)
//	{
//		int sum = 0;
//        for (j = 10; j < 10000; j = 10 * j)
//        {
//            sum += (i / j) * (i % j);
//        }
//		if (sum == i)
//			printf("%d ",i);
//	}
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    int i, j;
//    for (i = 10000; i < 99999; i++)
//    {
//        int sum = 0;
//        for (j = 10; j <= 10000; j = 10 * j)
//        {
//            sum += (i / j) * (i % j);
//        }
//        if (sum == i)
//            printf("%d ", i);
//    }
//    return 0;
//}
//

//#include<stdlib.h>
//
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	int* p = (int*)malloc(n * sizeof(int));
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d", (p + i));
//	}
//	int del;
//	scanf("%d",&del);
//	for (int j = 0; j < n;j++)
//	{
//		if (*(p + j) != del)
//			printf("%d ", *(p + j));
//	}
//	p = NULL;
//	return 0;
//}

//#include<stdio.h>
//#define MAX 100
//int main()
//{
//    auto int n = 0, x = 0, arr[MAX];
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    scanf("%d", &x);
//    for (int i = 0; i < n; i++)
//    {
//        if (arr[i] != x)
//        {
//            printf("%d ", arr[i]);
//        }
//    }
//    return 0;
//}

//
//int main()
//{
//
//	FILE* p = fopen("test.txt", "w");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	char ch;
//	for (ch = 'a'; ch <= 'z'; ch++)
//	{
//		fputc(ch, p);
//	}
//	fclose(p);
//	p = NULL;
//
//	return 0;
//}

//int main()
//{
//
//	FILE* p = fopen("test.txt", "r");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	int ch = 0;
//	while ((ch = fgetc(p)) != EOF)
//		printf("%c", ch);
//
//
//	fclose(p);
//	p = NULL;
//
//	return 0;
//}

//int main()
//{
//
//	FILE* p = fopen("test.txt", "w");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	fputs("abcde", p);
//	fputs("ÍôÇÕ", p);
//
//
//	fclose(p);
//	p = NULL;
//
//	return 0;
//}

//int main()
//{
//
//	FILE* p = fopen("test.txt", "r");
//	if (p == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	char arr[20];
//	while (fgets(arr, 20, p) != NULL)
//		printf("%s", arr);
//
//
//	fclose(p);
//	p = NULL;
//
//	return 0;
//}
