#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

class Date
{
public:
	void Init(int year, int month, int day);//声明定义分开就不是内联


private:
	int _year;
	int _month;
	int _day;
};

void Date::Init(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

//int main()
//{
//	int a = 2;
//	const int& rb = a * 3;//a*3的结果会先保存在一个临时对象中
//
//	double d = 12.34;
//	const int& rd = d;//类型转换中也会产生临时对象
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
////#define Add(x,y) ((x)+(y))
//
//inline int Add(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int a = 2;
//	cout << Add(a, a) << endl;
//	return 0;
//}

//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
////参数类型不同，构成函数重载
//int main()
//{
//	//f(NULL);//NULL展开为0所以调用第一个函数，但实际是想调用第二个
//	////f((void*)NULL); 编译报错: error C2665: “f”: 2 个重载中没有⼀个可以转换所有参数类型
//	//f((int*)NULL);//调用第二个函数
//	//f(nullptr);//调用第二个函数
//	int value = 1024;
//	char condition = *((char*)(&value));
//	if (condition) value += 1; condition = *((char*)(&value));
//	if (condition) value += 1; condition = *((char*)(&value));
//	printf("%d %d", value, condition);
//	return 0;
//}

#include <iostream>
using namespace std;

int fun(int i)
{
    if (i == 0)
        return 1;
    int j = i * i;
    while (i)
    {
        if (i % 10 != j % 10)
        {
            return 0;
        }
        i /= 10;
        j /= 10;
    }
    return 1;
}

int main() {
    int n = 0;
    int ans = 0;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        if (fun(i))
        {
            ans++;
        }
    }
    cout << ans << endl;
}