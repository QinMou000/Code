#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//int main()
//{
//	int money; 
//	scanf("%d",&money);
//	int count = money;
//	int lose = 0;
//	while (money!=1)
//	{
//		count += money / 2;
//		money /= 2;
//		lose += money % 2;
//		if (lose % 2 == 0)
//		{
//			count += lose / 2;
//			lose = 0;
//		}
//	}
//	printf("%d\n",count);
//	return 0;
//}

//int main()
//{
//	//13行13列  0 1 2 3 4 5 6 7 8 9 10 11 12 13
//	int x = 6;
//	int y = 6;
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 13; j++)
//		{
//			if (j >= x && j <= y)
//			{
//				printf("*");
//			}
//			else
//			{
//				printf(" ");
//			}
//		}
//		printf("\n");
//		x--;
//		y++;
//	}
//	for (int i = 6; i < 13; i++)
//	{
//		for (int j = 0; j < 13; j++)
//		{
//			if (j >= x && j <= y)
//			{
//				printf("*");
//			}
//			else
//			{
//				printf(" ");
//			}
//		}
//		printf("\n");
//		x++;
//		y--;
//	}
//	return 0;
//}

#include<math.h>

//int main()//水仙花数
//{
//	for (int i = 0; i <= 100000; i++)
//	{
//		int len = 0;
//		int j = i;
//		int ret = i;
//		int x = i;
//		int root = 0;
//		while (ret)
//		{
//			ret /= 10;
//			len++;
//		}
//		while (j)
//		{
//			root += pow(j % 10, len);
//			j /= 10;
//		}
//		if (root == x)
//		{
//			printf("%d ",x);
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int a;
//	int sum = 0;
//	scanf("%d", &a);
//	int b = a;
//	for (int i = 1; i < 6; i++)
//	{
//		sum += a;
//		a =a+pow(10,i)*b;
//	}
//	printf("%d\n",sum);
//	return 0;
//}