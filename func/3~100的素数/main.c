//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 3; i <= 100; i++)
//	{
//		//�ж�i�Ƿ�������
//		//������������ʹ�ӡ����������������
//		//��2~i-1֮�������ȥ�����Գ�i�����������һ������������i��i�Ͳ�������
//		//������е����ֶ���������i��i��������
//		int j = 0;
//		int flag = 1;//����i������
//		for (j = 2; j <= i - 1; j++)//2~8
//		{
//			if (i % j == 0)
//			{
//				flag = 0;//֤����������
//				break;
//			}
//		}
//		if (flag == 1)//������
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\nһ����%d������\n", count);
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
