#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	int a = 1;//sizeof�����ȡ���ݣ�ֻ�������ռ�ڴ�ռ�Ĵ�С����λ���ֽڣ�
//	printf("%zd\n", sizeof(a));  //4
//	printf("%zd\n", sizeof a );  //4
//	printf("%zd\n", sizeof 1);   //4
//	return 0;
//}

//int main()
//{
//	int a = 3;
//	int b = 5;
//	printf("%zd\n", sizeof(a += b));
//	printf("%d\n",a);//��Ϊa+=b���������ôa��ֵ����3��
//	return 0;
//}
//size_t strlen(const char* str);

int main()
{
	char a[] = "abc";
	char b[] = { 'a','b','c' };
	printf("%zd\n", strlen(a));//3       a���ڴ����ǣ� a b c \0 ������strlen��ȡ��\0ǰ����ַ�����
	printf("%zd\n", strlen(b));//���ֵ  b���ڴ����ǣ� a b c ���ֵ���� �����ģ��������ǲ�֪������ʲô�ط������\0
	printf("%zd\n", sizeof(a));//4       a����\0����ռ���ĸ��ֽ�
	printf("%zd\n", sizeof(b));//3       bֻ������abc�����ַ�����ռ�����ֽ�
	return 0;
}
