#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	int a = 1;//sizeof不会读取数据，只会计算所占内存空间的大小（单位是字节）
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
//	printf("%d\n",a);//因为a+=b不会计算那么a的值还是3。
//	return 0;
//}
//size_t strlen(const char* str);

int main()
{
	char a[] = "abc";
	char b[] = { 'a','b','c' };
	printf("%zd\n", strlen(a));//3       a在内存中是： a b c \0 这样的strlen读取了\0前面的字符个数
	printf("%zd\n", strlen(b));//随机值  b在内存中是： a b c 随机值…… 这样的，所以我们不知道后面什么地方会出现\0
	printf("%zd\n", sizeof(a));//4       a包括\0在内占了四个字节
	printf("%zd\n", sizeof(b));//3       b只包括了abc三个字符所以占三个字节
	return 0;
}
