#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//template<class T>
//void Swap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	//int a = 3, b = 5;
//	//float x = 1.2f, y = 2.2f;
//	//
//	//Swap(a, b);
//	//Swap(x, y);
//	string s1;
//	string s2("12345");
//
//	cout << s1 << s2;
//	return 0;
//}
//
//class A
//{
//public:
//	A()
//		:_a(1)
//		,_b(2)
//	{}
//	void Print()
//	{
//		cout << _a << " " << _b << endl;
//	}
//private:
//	int _a;
//	int _b;
//};

//class AnotherClass
//{
//
//};
//
//class MyClass {
//public:
//    // 常量成员
//    const int constVar;
//    // 引用成员
//    int& refVar;
//    // 没有默认构造函数的类类型成员
//    AnotherClass obj;
//
//    MyClass(int value, int& ref, AnotherClass objParam)
//        : constVar(value), refVar(ref), obj(objParam) {}
//};
//
//int main()
//{
//    MyClass x;
//
//    return 0;
//}

//int main()
//{
//	A a1;
//	a1.Print();
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2 = 2;
//	int _a1 = 2;
//};
//int main()
//{
//	A aa(1);
//	aa.Print();
//}

#include<iostream>
using namespace std;
class A
{
public:
	//构造函数explicit就不再⽀持隐式类型转换
	 //explicit A(int a1)
		A(int a1)
		:_a1(a1)
	{}
	//explicit A(int a1, int a2)
	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{}
	void Print() const
	{
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a1 = 1;
	int _a2 = 2;
};
int main()
{
	// 1构造⼀个A的临时对象，再⽤这个临时对象拷⻉构造aa3
	// 编译器遇到连续构造+拷⻉构造->优化为直接构造
	A aa1 = 1;
	aa1.Print();
	const A& aa2 = 1;
	aa2.Print();
	// C++11之后才⽀持多参数转化
	A aa3 = { 2,2 };
	aa3.Print();
	return 0;
}

