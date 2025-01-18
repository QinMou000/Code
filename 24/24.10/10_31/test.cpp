#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

struct Point
{
	int _x;
	int _y;
};

//int main()
//{
//	int array1[] = { 1, 2, 3, 4, 5 };
//	int array2[5] = { 0 };
//	Point p = { 1, 2 };
//	return 0;
//}
//int main()
//{
//	// 左值：可以取地址
//	// 以下的p、b、c、*p、s、s[0]就是常⻅的左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = b;
//	*p = 10;
//	string s("111111");
//	s[0] = 'x';
//	cout << &c << endl;
//	cout << (void*)&s[0] << endl;
//	// 右值：不能取地址
//	double x = 1.1, y = 2.2;
//	// 以下⼏个10、x + y、fmin(x, y)、string("11111")都是常⻅的右值
//	10;
//	x + y;
//	fmin(x, y);
//	string("11111");
//	//cout << &10 << endl;
//	//cout << &(x+y) << endl;
//	//cout << &(fmin(x, y)) << endl;
//	//cout << &string("11111") << endl;
//	return 0;
//}


//int main()
//{
//	// 左值：可以取地址
//	int b = 1;
//	// 左值引⽤给左值取别名
//	int& r1 = b;
//	// 右值引⽤给右值取别名
//	int&& rr1 = 10;
//
//	return 0;
//}


//int main()
//{
//	std::string s1 = "Test";
//	// std::string&& r1 = s1; // 错误：不能绑定到左值
//
//	const std::string& r2 = s1 + s1; // OK：到 const 的左值引用延长生存期
//	// r2 += "Test"; // 错误：不能通过到 const 的引⽤修改
//
//	std::string&& r3 = s1 + s1; // OK：右值引用延长生存期
//	r3 += "Test"; // OK：能通过到非 const 的引用修改
//	std::cout << r3 << '\n';// TestTestTest
//
//	return 0;
//}
#include<vector>
string addStrings(string num1, string num2) {
	string str;
	int end1 = num1.size() - 1, end2 = num2.size() - 1;
	// 进位
	int next = 0;
	while (end1 >= 0 || end2 >= 0)
	{
		int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
		int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
		int ret = val1 + val2 + next;
		next = ret / 10;
		ret = ret % 10;
		str += ('0' + ret);
	}
	if (next == 1)
		str += '1';
	reverse(str.begin(), str.end());
	return str;
}
vector<vector<int>> generate(int numRows) {
	vector<vector<int>> vv(numRows);
	for (int i = 0; i < numRows; ++i)
	{
		vv[i].resize(i + 1, 1);
	}
	for (int i = 2; i < numRows; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
		}
	}
	return vv;
}


//// 由于引⽤折叠限定，f1实例化以后总是⼀个左值引⽤
//template<class T>
//void f1(T& x)
//{}
//// 由于引⽤折叠限定，f2实例化后可以是左值引⽤，也可以是右值引⽤
//template<class T>
//void f2(T&& x)
//{}
//int main()
//{
//	typedef int& lref;
//	typedef int&& rref;
//	int n = 0;
//	lref& r1 = n; // r1 的类型是 int&
//	lref&& r2 = n; // r2 的类型是 int&
//	rref& r3 = n; // r3 的类型是 int&
//	rref&& r4 = 1; // r4 的类型是 int&&
//
//	// 没有折叠->实例化为void f1(int& x)
//	f1<int>(n);
//	f1<int>(0); // 报错
//	// 折叠->实例化为void f1(int& x)
//	f1<int&>(n);
//	f1<int&>(0); // 报错
//	// 折叠->实例化为void f1(int& x)
//	f1<int&&>(n);
//	f1<int&&>(0); // 报错
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&>(n);
//	f1<const int&>(0);
//	// 折叠->实例化为void f1(const int& x)
//	f1<const int&&>(n);
//	f1<const int&&>(0);
//	// 没有折叠->实例化为void f2(int&& x)
//	f2<int>(n); // 报错
//	f2<int>(0);
//	// 折叠->实例化为void f2(int& x)
//	f2<int&>(n);
//	f2<int&>(0); // 报错
//	// 折叠->实例化为void f2(int&& x)
//	f2<int&&>(n); // 报错
//	f2<int&&>(0);
//	return 0;
//}

//
//template<class T>
//void Function(T&& t)
//{
//	int a = 0;
//	T x = a;
//	//x++;
//	cout << &a << endl;
//	cout << &x << endl << endl;
//}
//int main()
//{
//	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(10); // 右值
//	int a;
//	// a是左值，推导出T为int&，引⽤折叠，模板实例化为void Function(int& t)
//	Function(a); // 左值
//	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//	Function(std::move(a)); // 右值
//	const int b = 8;
//	// a是左值，推导出T为const int&，引⽤折叠，模板实例化为void Function(const int&t)
//	// 所以Function内部会编译报错，x不能++
//	Function(b); // const 左值
//	// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&&t)
//	// 所以Function内部会编译报错，x不能++
//	Function(std::move(b)); // const 右值
//	return 0;
//}

template <class _Ty>
_Ty&& forward(remove_reference_t<_Ty>& _Arg) noexcept
{ // forward an lvalue as either an lvalue or an rvalue
	return static_cast<_Ty&&>(_Arg);
}
void Fun(int& x) { cout << "左值引⽤" << endl; }
void Fun(const int& x) { cout << "const 左值引⽤" << endl; }
void Fun(int&& x) { cout << "右值引⽤" << endl; }
void Fun(const int&& x) { cout << "const 右值引⽤" << endl; }

template < class T>
void Function(T && t)
{
	Fun(t);
	//Fun(forward<T>(t));
}
int main()
{
	// 10是右值，推导出T为int，模板实例化为void Function(int&& t)
	Function(10); // 右值
	int a;
	// a是左值，推导出T为int&，引⽤折叠，模板实例化为void Function(int& t)
	Function(a); // 左值
	// std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
	Function(std::move(a)); // 右值
	const int b = 8;
	// a是左值，推导出T为const int&，引⽤折叠，模板实例化为void Function(const int&t)
	Function(b); // const 左值
	// std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&&t)
	Function(std::move(b)); // const 右值
	return 0;
}