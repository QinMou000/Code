#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//int len = 0;
//
//void shift(int arr[])//����������ѭ������һλ
//{
//	int num = arr[0];
//	for (int i=0;i<len;i++)
//	{
//		arr[i] = arr[i + 1];
//	}
//	arr[len-1] = num;
//}
//
//int main()
//{
//	int arr1[9] = { 1,2,3,4,5,6,7,8,9 };
//	len= sizeof(arr1) / sizeof(arr1[0]);
//	//printf("%d ",len);
//	shift(arr1);
//	for (int i = 0; i < 9; i++)
//	{
//		printf("%d ",arr1[i]);
//	}
//	return 0;
//}

//int main()
//{
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10};
//	char arr2[10] = "abcdefghij";
//	printf("%d\n",sizeof(arr1));
//	printf("%d\n", sizeof(arr1[0]));
//	printf("%d\n", sizeof(arr2));
//	printf("%d\n", sizeof(arr2[0]));
//
//
//	printf("\n%d\n",strlen(arr1));
//	//printf("%d\n", strlen(arr1[0]));
//	printf("%d\n", strlen("abcdefghij"));
//	//printf("%d\n", strlen(arr2[0]));
//
//	printf("%d\n", sizeof("abcdefghij"));
//
//}

//void print(int num)//�����ӡÿһλ��
//{
//	if (num % 10 != 0)
//	{
//		printf("%d ", num % 10);
//	}
//	if (num % 10!=0)
//	{
//		print(num / 10);//�ݹ�YYDS����������
//	}
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d",&a);
//	print(a);
//	return 0;
//}

//int main()//������ĸ���������򣬴�д��ǰ��Сд�ں󣬴�ӡ
//{
//	char arr[1000] = {'0'};
//	char ch;
//	//for (int i = 0; i < 8; i++)
//	//{
//	//	scanf("%c",arr[i]);
//	//}
//	gets(arr);
//	int len = strlen(arr);
//	for (int j = 0; j < len; j++)
//	{
//		for (int i = j + 1; i <= len; i++)
//		{
//			if (arr[j] < arr[i])
//			{
//				ch = arr[j];
//				arr[j] = arr[i];
//				arr[i] = ch;
//			}
//		}
//	}
//	int num;
//	for (int i = 0; i < len; i++)
//	{
//		if (arr[i] > 'A' && arr[i] < 'Z')
//		{
//			num = i;
//			break;
//		}
//	}
//	for (int i = num; i < len; i++)
//	{
//		printf("%c ",arr[i]);
//	}
//	for (int i = 0; i < num; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//	//puts(arr);
//	return 0;
//}

//int main()//����1+2+3+...+n-l +n +n-l +n-2 + ...+ 3+2+1������n Ϊ�û�����ġ�
//{
//	int num = 0;
//	int sum = 0;
//	scanf("%d",&num);
//	for (int i =1 ; i < num; i++)
//	{
//		sum = sum + i;
//	}
//	sum = sum * 2 + num;
//	printf("%d ",sum);
//	return 0;
//}

//int len;
//
//void test(int arr[])//��дһ��void�͵ĺ���, �ú����Ľ���һ�����飬���Դ�ӡ�����е����ֵ����Сֵ��
//{
//	for (int i = 0; i < len-1; i++)
//	{
//		for (int j = i; j < len; j++)
//		{
//			if (arr[i] < arr[j])
//			{
//				int num = arr[i];
//				arr[i] = arr[j];
//				arr[j] = num;
//			}
//		}
//	}
//	printf("���ֵ��%d\n",arr[0]);
//	printf("��Сֵ��%d\n", arr[len-1]);
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	len = sizeof(arr) / sizeof(arr[0]);
//	test(arr);
//	return 0;
//}

void test(int arr[])//��дһ��void�͵ĺ���, �ú����Ľ���һ�����飬���Դ�ӡ�����е����ֵ����Сֵ��
{
	int len = strlen(arr);
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i; j < len; j++)
		{
			if (arr[i] < arr[j])
			{
				int num = arr[i];
				arr[i] = arr[j];
				arr[j] = num;
			}
		}
	}
	printf("���ֵ��%d\n",arr[0]);
	printf("��Сֵ��%d\n", arr[len-1]);
}

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	test(arr);//����������и���bug�ȴ��޸�������
	return 0;
}