#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//void Nicomachus(int n)
//{
//	int num = n * n * n;
//	if()
//}
//
//int main()//��֤��Ƴ�˹����
//{
//	int n;
//	scanf("%d",&n);
//	Nicomachus(n);
//	return 0;
//}

int main()
/*
	�Ȳ����� 2��5��8��11��14��������
	���� 2 ��ʼ�� 3 Ϊ����ĵȲ����У�
	�����Ȳ�����ǰn���
*/
{
	int n;
	scanf("%d",&n);
	float ret = 2*n + n * (n - 1) * 1.5;
	printf("%.0f\n",ret);
	return 0;
}