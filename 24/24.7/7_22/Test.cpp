#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

//template<class T>
//T Swap(T x, T y){
//	T tmp = x;
//	x = y;
//	y = tmp;
//}
//int main()
//{
//	int a = 2;
//	int b = 3;
//	int ret1 = Swap(a, b);
//
//	double m = 1.0;
//	double n = 2.0;
//	double ret1 = Swap(m, n);
//
//	char p = '3';
//	char q = '4';
//	char ret1 = Swap(p, q);
//
//	return 0;
//}
//
//int& Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//double& Swap(double& left, double& right)
//{
//	double temp = left;
//	left = right;
//	right = temp;
//}
//char& Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}


//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	Add(a1, a2);
//	Add(d1, d2);
//	/*
//	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有
//	一个T，编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//	Add(a1, d1);
//	*/
//	// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化
//	Add(a1, (int)d1);
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	double b = 20.0;
//	// 显式实例化
//	Add<int>(a, b);
//	return 0;
//}

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	Add<int>(1, 2); // 调用编译器特化的Add版本
//}

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//}

//template<class T1, class T2, ……, class Tn>
//class 类模板名
//{
//	// 类内成员定义
//};
//#include<iostream>
//using namespace std;
//// 类模版
//template<typename T>
//class Stack
//{
//public:
//	Stack(size_t capacity = 4)
//	{
//		_array = new T[capacity];
//		_capacity = capacity;
//		_size = 0;
//	}
//	void Push(const T& data);
//private:
//	T* _array;
//	size_t _capacity;
//	size_t _size;
//};
//// 模版不建议声明和定义分离到两个文件.h 和.cpp会出现链接错误
//template<class T>
//void Stack<T>::Push(const T& data)
//{
//	// 扩容
//	_array[_size] = data;
//	++_size;
//}
//int main()
//{
//	Stack<int> st1; // int
//	Stack<double> st2; // double
//	return 0;
//}

//// Stack是类名，Stack<int>才是类型
//Stack<int> st1; // int
//Stack<double> st2; // double

int main()
{
	string a = "hello world";
	string b = a;
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	string c = b;
	c = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	a = "";
	if (a.c_str() == b.c_str())
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;
	return 0;

}