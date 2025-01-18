#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//#include"vld.h"
//#define FUN(n) (((n&0x55555555)<<1)|((n&0xaaaaaaaa)>>1))
//
//int main()
//{
//	int a = 13;
//	printf("%d\n",FUN(a));
//
//	return 0;
//}
//struct S
//{
//	char name[20];
//	int age;
//};
//
//#define MY_OFFSETOF(T,m) (size_t)(&((T*)0)->m)
//int main()
//{
//	printf("%zd\n",MY_OFFSETOF(struct S,age));
//	return 0;
//}

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int a, b;
//	int min = 0;
//	int max = _CRT_INT_MAX;
//	while (n--)
//	{
//		scanf("%d %d", &a, &b);
//		if (a / b < max)
//			max = a / b;
//		if (a / (b + 1) > min)
//			min = a / (b + 1);
//	}
//	printf("%d %d",min+1,max);
//	return 0;
//}
#include <iostream> 
using namespace std;
int main()
{
    int m, a, b, Min = 0, Max = 0, flags = 0;//flags标记是否为第一次输入
    cin >> m;
    while (m--)//表示输入m组数据
    {
        cin >> a >> b;//输入普通金属、特殊金属数量
        if (a / b < Max && flags == 1)//维护上限最小值
        {
            Max = a / b;
        }
        if (a / (b + 1) > Min && flags == 1)//维护下限最大值
        {
            Min = a / (b + 1);
        }
        if (flags == 0)//让第一次输入的数据作为大小判断的成员，这样就不用考虑Max、Min的初始值
        {
            Max = a / b;
            Min = a / (b + 1);
            flags = 1;//标记已经初始化
        }
    }
    cout << Min + 1 << " " << Max;//因为下线不能触碰，得加1
    return 0;
}

