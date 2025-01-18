#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
//int main()
//{
//    unsigned char puc[4];
//    struct tagPIM
//    {
//        unsigned char ucPim1;
//        unsigned char ucData0 : 1;
//        unsigned char ucData1 : 2;
//        unsigned char ucData2 : 3;
//    }*pstPimData;
//    pstPimData = (struct tagPIM*)puc;
//    memset(puc, 0, 4);
//    pstPimData->ucPim1 = 2;
//    pstPimData->ucData0 = 3;
//    pstPimData->ucData1 = 4;
//    pstPimData->ucData2 = 5;
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//    return 0;
//}

//union X
//{
//	int i;
//	char j;
//}x;
//
//bool Check()
//{
//	x.i = 1;
//	return x.j;
//}
//int main()
//{
//	printf("%d\n",Check());
//	return 0;
//}

//struct Book
//{
//	char name[20];//书名
//	char author[20];//作者
//	int price;//定价
//};
//练习1


//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
////练习2
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
////练习3
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
////练习4-结构体嵌套问题
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//
//int main()
//{
//
//	printf("%zd\n", sizeof(struct S1));
//
//	printf("%zd\n", sizeof(struct S2));
//
//	printf("%zd\n", sizeof(struct S3));
//
//	printf("%zd\n", sizeof(struct S4));
//
//	return 0;
//}
//#include <stdio.h>
//#pragma pack(1)//设置默认对⻬数为1
//struct S
//{
//    char c1;
//    int i;
//    char c2;
//};
//#pragma pack()//取消设置的对⻬数，还原为默认
//int main()
//{
//    //输出的结果是什么？
//    printf("%zd\n", sizeof(struct S));
//    return 0;
//}
//#include<stdio.h>
//struct a
//{
//    int _a : 2;
//    int _b : 5;
//    int _c : 10;
//    int _d : 30;
//};
//
//int main()
//{
//    printf("%zd\n",sizeof(struct a));
//    return 0;
//}

//int main()
//{
//	int a = 0;
//	return 0;
//}
struct A
{
    int _a : 2;
    int _b : 5;
    int _c : 10;
    int _d : 30;
};
int main()
{
    struct A sa = { 0 };
    /*
        scanf("%d", &sa._b);//这是错误的
    */
    //正确的⽰范
    int b = 0;
    scanf("%d", &b);
    sa._b = b;
    return 0;
}
