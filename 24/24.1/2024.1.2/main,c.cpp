#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
//int main()//牛逼克拉斯！！
//{
//	int a = 1;
//	int b = 2;
//	printf("%%d,%%d",a,b);
//	return 0;
//}

//int main()//屌哥
//{
//	char ch1 = 'D' + '8' - '3';
//	char ch2 = '9' - '1';
//	printf("%c %d",ch1,ch2);
//	char a = '\0';
//	char b = '0';
//	printf("\n%c %c",a,b);
//	return 0;
//}


//int main()
//{
//	float a = 20;
//	float b = 3.0;
//	float c = a / b;
//	printf("%d \n",int (a/b+0.5));
//	int num = round(c);
//	printf("%d ", num);
//	
//	return 0;
//}

//int main()//！！！！！！！！！！！！！！！！！！四舍五入！！！！！！！！！！！！！！！！！！！！！！！！
//{
//	float a = 3.141592653;
//	printf("%.4f", a);
//	return 0;
//}

//int main()
//{
//	for (int i = 1; i < 6; i++)
//	{
//		if (i % 2 != 0)
//		{
//			printf("#");
//			continue;
//		}
//		printf("*");
//	}
//	printf("\n");
//
//	char ch[] = {"jashfkjewjk"};
//	printf("%d ", strlen("jashfkjewjk") );
//	printf("%d \n", sizeof("jashfkjewjk") );
//
//
//	printf("%d ", strlen(ch));
//	printf("%d \n", sizeof(ch));
//	return 0;
//}

int get_count(char* arr)
{
	if (*arr != '\0')
	{
		return 1 + get_count(arr+1);
	}
	else
	{
		return 0;
	}
}

int main()
{
	char arr[] = "bit" ;
	int count = get_count(arr);

	printf("%d ",count);
	return 0;
}