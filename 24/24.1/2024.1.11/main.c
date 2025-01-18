#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//int main()
// /*
// 首先输入要输入的整数个数 n ，然后输入 n 个整数。输出为 n 个整数中负数的个数，和所有正整数的平均值，
// 结果保留一位小数。
// */
//{
//	int num;
//	float average;
//	int arr[] = { 0 };
//	int a = 0, b = 0;
//	int sum=0;
//	scanf("%d",&num);
//	for (int i = 0; i < num; i++)
//	{
//		scanf("%d",&arr[i]);
//	}
//	for (int i = 0; i < num;i++)
//	{
//		if (arr[i] < 0)
//		{
//			a++;
//		}
//	}
//	for (int i = 0; i < num; i++)
//	{
//		if (arr[i] > 0)
//		{
//			sum += arr[i];
//			b++;
//		}
//	}
//	average = sum / b;
//	printf("\n负数有%d个\n", a);
//	printf("正整数的均值为：%.1f\n",average);
//	return 0;
//}

//int main()
//{
//	float a = 3.141592653;
//	printf("%.4fs\n",a);
//	int b = 3.5;
//	printf("%d\n",b);
//	return 0;
//}

//void main()
//{
//	float r, area;
//	scanf("%f",&r);
//	area = 0.5 * r * r;
//	printf("area = %f\n",area);
//}

//int select_smallest(int arr[])
//{
//	int len = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < len-1; i++)
//	{
//		for (int j = i; j < len; j++)
//		{
//			if (arr[i]>arr[j])
//			{
//				int x = arr[i];
//				arr[i] = arr[j];
//				arr[j] = x;
//			}
//		}
//	}
//	return arr[0];
//}
//
//int main()
//{
//	int arr[] = { 1,2,0,4 };
//	int a=select_smallest(arr);
//	printf("%d\n",a);
//	return 0;
//}


//int main()
//{
//	int arr1[2][3] = { {1,2,3},{4,5,6} };
//	for (int i=0;i<2;i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			printf("%d ",arr1[i][j]);
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

int main()
{
	static char arr1[] = { 1,2,3,4,5 };
	static char arr2[] = { '1','2','3','4','5' };
	int a = strlen(arr1);
	int b = strlen(arr2);
	printf("%d\n", a);
	printf("%d\n", b);
	char d[5] = "abcde";
	char e[5] = "";
	char f[5] = { "abc" };
	char g[5] = { 'a','b','c' };
	char h = '66';
	printf("\n%c\n ",h);
	return 0;
}