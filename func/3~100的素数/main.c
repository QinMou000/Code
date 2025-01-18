//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 3; i <= 100; i++)
//	{
//		//判断i是否是素数
//		//如果是素数，就打印，不是素数就跳过
//		//拿2~i-1之间的数字去挨个试除i，如果其中有一个数字整除了i，i就不是素数
//		//如果所有的数字都不能整除i，i就是素数
//		int j = 0;
//		int flag = 1;//假设i是素数
//		for (j = 2; j <= i - 1; j++)//2~8
//		{
//			if (i % j == 0)
//			{
//				flag = 0;//证明不是素数
//				break;
//			}
//		}
//		if (flag == 1)//是素数
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\n一共有%d个素数\n", count);
//	return 0;
//}



#include <stdio.h>
int main()
{
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	i = a++ && ++b && d++;
	//i = a++||++b||d++;
	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);
	return 0;
}
