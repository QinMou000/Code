#define _CRT_SECURE_NO_WARNINGS 1
// 实现⼀个类，计算程序中创建出了多少个类对象？
//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A()
//	{
//		++_scount;
//	}
//	A(const A& t)
//	{
//		++_scount;
//	}
//	~A()
//	{
//		--_scount;
//	}
//	static int GetACount()
//	{
//		return _scount;
//	}
//private:
//	// 类⾥⾯声明
//	static int _scount;
//};
//// 类外⾯初始化
//int A::_scount = 0;
//int main()
//{
//	cout << A::GetACount() << endl;
//	A a1, a2;
//	A a3(a1);
//	cout << A::GetACount() << endl;
//	cout << a1.GetACount() << endl;
//	//编译报错：error C2248: “A::_scount”: ⽆法访问 private 成员(在“A”类中声明)
//	//cout << A::_scount << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//// 前置声明，否则A的友元函数声明编译器不认识B，编译器都是从上到下识别的
//class B;
//class A
//{
//	// 外部函数友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//	// 外部函数友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//void func(const A& aa, const B& bb)
//{
//	cout << aa._a1 << endl;// 访问类里面的私有成员变量
//	cout << bb._b1 << endl;
//}
//int main()
//{
//	A aa;
//	B bb;
//	func(aa, bb);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class A
//{
//	// 类友元声明
//	friend class B;
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//class B
//{
//public:
//	void func1(const A& aa)
//	{
//		cout << aa._a1 << endl;// 访问友元类的私有成员变量
//		cout << _b1 << endl;
//	}
//	void func2(const A& aa)
//	{
//		cout << aa._a2 << endl;// 访问友元类的私有成员变量
//		cout << _b2 << endl;
//	}
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//int main()
//{
//	A aa;
//	B bb;
//	bb.func1(aa);
//	bb.func1(aa);
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//class A
//{
//	class B {
//	public:
//		void fun(const A& b)
//		{
//
//		}
//	private:
//		int _b = 1;
//	};
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};

//#include<iostream>
//using namespace std;
//class A
//{
//private:
//	static int _k;
//	int _h = 1;
//public:
//	class B // B默认就是A的友元
//	{
//	public:
//		void foo(const A & a)
//		{
//			cout << _k << endl; 
//			cout << a._h << endl; // 内部类可以访问外部类的私有成员变量类，
//			                      // 但外部不能突破内部类的访问限定符
//		}
//	};
//};
//int A::_k = 1;
//int main()
//{
//	cout << sizeof(A) << endl;
//	A::B b;
//	A aa;
//	b.foo(aa);
//	return 0;
//}

//#include<iostream>
//using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		:_a(a)
//	{
//		cout << "A(int a)" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//private:
//	int _a;
//};
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//...
//		return n;
//	}
//};
//int main()
//{
//	A aa1;
//	// 不能这么定义对象，因为编译器⽆法识别下⾯是⼀个函数声明，还是对象定义
//	//A aa1();
//	// 但是我们可以这么定义匿名对象，匿名对象的特点不⽤取名字，
//	// 但是他的⽣命周期只有这⼀⾏，我们可以看到下⼀⾏他就会⾃动调⽤析构函数
//	A();
//	A(1);
//	A aa2(2);
//	// 匿名对象在这样场景下就很好⽤，当然还有⼀些其他使⽤场景，这个以后遇到了再说
//	Solution().Sum_Solution(10);// 你只想调用以下这个类里面的某个函数
//	return 0;
//}

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
int main()
{
	// 传值传参
	A aa1;
	f1(aa1);
	cout << endl;
	// 隐式类型，连续构造+拷⻉构造->优化为直接构造
	f1(1);
	// ⼀个表达式中，连续构造+拷⻉构造->优化为⼀个构造
	f1(A(2));
	cout << endl;
	cout << "***********************************************" << endl;
	// 传值返回
	// 返回时⼀个表达式中，连续拷⻉构造+拷⻉构造->优化⼀个拷⻉构造 （vs2019）
	// ⼀些编译器会优化得更厉害，进⾏跨⾏合并优化，直接变为构造。（vs2022）
	f2();
	cout << endl;
	// 返回时⼀个表达式中，连续拷⻉构造+拷⻉构造->优化⼀个拷⻉构造 （vs2019）
	// ⼀些编译器会优化得更厉害，进⾏跨⾏合并优化，直接变为构造。（vs2022）
	A aa2 = f2();
	cout << endl;
	// ⼀个表达式中，连续拷⻉构造+赋值重载->⽆法优化
	aa1 = f2();
	cout << endl;
	return 0;
}

//C c;
//int main()
//{
//	A a;
//	B b;
//	static D d;
//	return;
//}

