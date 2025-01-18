#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
class A
{
public:
	A(int a = 0)
		:_a1(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;
	}
	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
				_a1 = aa._a1;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a1 = 1;
};
void f1(A aa)
{}
A f2()
{
	A aa;
	return aa;
}
//int main()
//{
//	// 传值传参
//	A aa1;
//	f1(aa1);
//	cout << endl;
//	// 隐式类型，连续构造+拷⻉构造->优化为直接构造
//	f1(1);
//	// ⼀个表达式中，连续构造+拷⻉构造->优化为⼀个构造
//	f1(A(2));
//	cout << endl;
//	cout << "***********************************************" << endl;
//	// 传值返回
//	// 返回时⼀个表达式中，连续拷⻉构造+拷⻉构造->优化⼀个拷⻉构造 （vs2019）
//	// ⼀些编译器会优化得更厉害，进⾏跨⾏合并优化，直接变为构造。（vs2022）
//	f2();
//	cout << endl;
//	// 返回时⼀个表达式中，连续拷⻉构造+拷⻉构造->优化⼀个拷⻉构造 （vs2019）
//	// ⼀些编译器会优化得更厉害，进⾏跨⾏合并优化，直接变为构造。（vs2022）
//	A aa2 = f2();
//	cout << endl;
//	// ⼀个表达式中，连续拷⻉构造+赋值重载->⽆法优化
//	aa1 = f2();
//	cout << endl;
//	return 0;
//}

// 静态区
// 静态区
// 静态区
// 
// 栈
// 栈

// A D C  D A A 

void func()
{
	int n = 1;
	while(1)
	{
		void* p1 = new char[1024 * 1024];
		++n;
		cout << p1 << "  " << n << endl;
	}
}

int main()
{
	int* p = new int(1);
	int* p1 = new int[10] {};
	
	delete p;
	delete[] p1;
	 
	//try
	//{
	//	func();
	//}
	//catch(const exception& e)
	//{
	//	cout << e.what() << endl;
	//}
	return 0;
}