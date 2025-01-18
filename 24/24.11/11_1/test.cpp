#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
//
//int main()
//{
//	double x = 2.2;
//	Print(); // 包⾥有0个参数
//	Print(1); // 包⾥有1个参数
//	Print(1, string("xxxxx")); // 包⾥有2个参数
//	Print(1.1, string("xxxxx"), x); // 包⾥有3个参数
//	return 0;
//}
//
//template <class ...Args>
//void Print(Args&&... args)
//{
//	cout << sizeof...(args) << endl;
//}
//
//
//// 原理2：编译本质这⾥会结合引⽤折叠规则实例化出以下四个函数
//void Print();
//void Print(int&& arg1);
//void Print(int&& arg1, string&& arg2);
//void Print(double&& arg1, string&& arg2, double& arg3);
//
//
//// 原理1：更本质去看没有可变参数模板，我们实现出这样的多个函数模板才能支持
//// 这里的功能，有了可变参数模板，我们进一步被解放，他是类型泛化基础
//// 上叠加数量变化，让我们泛型编程更灵活。（相当于是模板的模板）
//void Print();
//template <class T1>
//void Print(T1&& arg1);
//template <class T1, class T2>
//void Print(T1&& arg1, T2&& arg2);
//template <class T1, class T2, class T3>
//void Print(T1&& arg1, T2&& arg2, T3&& arg3);


void ShowList()
{
	// 编译器时递归的终⽌条件，参数包是0个时，直接匹配这个函数
	cout << endl;
}
//template <class T, class ...Args>
//void ShowList(T x, Args... args)
//{
//	cout << x << " ";
//	// args是N个参数的参数包
//	// 调⽤ShowList，参数包的第⼀个传给x，剩下N-1传给第⼆个参数包
//	ShowList(args...);
//}
//// 编译时递归推导解析参数
//template <class ...Args>
//void Print(Args... args)
//{
//	ShowList(args...);
//}
//int main()
//{
//	Print();
//	Print(1);
//	Print(1, string("xxxxx"));
//	Print(1, string("xxxxx"), 2.2);
//	return 0;
//}

//template <class T>
//const T& GetArg(const T& x)
//{
//	cout << x << " ";
//	return x;
//}
//template <class ...Args>
//void Arguments(Args... args)
//{}
//template <class ...Args>
//void Print(Args... args)
//{
//	// 注意GetArg必须返回或者到的对象，这样才能组成参数包给Arguments
//	Arguments(GetArg(args)...);
//}


//template <class T, class ...Args>
//void ShowList(T x, Args... args)
//{
//	 cout << x << " ";
//	 Print(args...);
//}
//void ShowList(double x)
//{
//	 cout << x << " ";
//	 ShowList();
//}
//void ShowList(string x, double z)
//{
//	 cout << x << " ";
//	 ShowList(z);
//}
//void ShowList(int x, string y, double z)
//{
//	 cout << x << " ";
//	 ShowList(y, z);
//}
//void Print(int x, string y, double z)
//{
//	ShowList(x, y, z);
//}
////Print(1, string("xxxxx"), 2.2);调⽤时
////本质编译器将可变参数模板通过模式的包扩展，编译器推导的以上三个重载函数

//void Print(int x, string y, double z)
//{
//	Arguments(GetArg(x), GetArg(y), GetArg(z));
//}

#include<list>
//int main()
//{
//	list<string> lt;
//	//传左值，跟push_back⼀样，⾛拷贝构造
//	string s1 = "11111";
//	lt.emplace_back(s1);
//	//右值，跟push_back⼀样，⾛移动构造
//	lt.emplace_back(move(s1));
//	cout << "*********************************" << endl;
//
//	// 直接把构造string参数包往下传，直接⽤string参数包构造string
//	// 这⾥达到的效果是push_back做不到的
//	lt.emplace_back("111111111111");
//	cout << "*********************************" << endl;
//
//	list<pair<string, int>> lt1;
//	// 跟push_back⼀样
//	// 构造pair + 拷贝/移动构造pair到list的节点中data上
//	pair<string, int> kv("苹果", 1);
//	lt1.emplace_back(kv);
//	// 跟push_back⼀样
//	lt1.emplace_back(move(kv));
//	cout << "*********************************" << endl;
//
//	// 直接把构造pair参数包往下传，直接⽤pair参数包构造pair
//	// 这⾥达到的效果是push_back做不到的
//	lt1.emplace_back("苹果", 1);
//	cout << "*********************************" << endl;
//
//	return 0;
//}

//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//		Person(const Person & p)
//		:_name(p._name)
//		, _age(p._age)
//	{}
//	Person(Person&& p) = default;//强制编译器生成此类构造函数
//
//	//Person(const Person& p) = delete;
//	//编译器不会再自动生成此类构造函数
//private:
//	string _name;
//	int _age;
//};
//int main()
//{
//	Person s1;
//	Person s2 = s1;
//	Person s3 = std::move(s1);
//	return 0;
//}

//int main()
//{
//	// ⼀个简单的lambda表达式
//	auto add1 = [](int x, int y)->int {return x + y; };
//	cout << add1(1, 2) << endl;
//	// 1、捕捉为空也不能省略
//	// 2、参数为空可以省略
//	// 3、返回值可以省略，可以通过返回对象⾃动推导
//	// 4、函数体不能省略
//	auto func1 = []
//	{
//		cout << "hello Qin" << endl;
//		return 0;
//	};
//	func1();
//	int a = 0, b = 1;
//	auto swap1 = [](int& x, int& y)
//	{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//	swap1(a, b);
//	cout << a << ":" << b << endl;
//	return 0;
//}


//int main()
//{
//	auto add = [](int a, int b) {return a + b; };
//	cout << add(1, 2);
//
//	return 0;
//}
//
//int a = 0, b = 1, c = 2, d = 3;
//// 传值捕捉本质是⼀种拷贝,并且被const修饰了
//// mutable相当于去掉const属性，可以修改了
//// 但是修改了不会影响外⾯被捕捉的值，因为是⼀种拷贝
//auto func7 = [=]()mutable
//{
//	a++;
//	b++;
//	c++;
//	d++;
//	return a + b + c + d;
//};
#include<vector>
#include<algorithm>
using namespace std;
//struct Goods
//{
//	string _name; // 名字
//	double _price; // 价格
//	int _evaluate; // 评价
//	// ...
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{}
//};
//
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "⾹蕉", 3, 4 }, { "橙⼦", 2.2, 3
//	}, { "菠萝", 1.5, 4 } };
//	// 类似这样的场景，我们实现仿函数对象或者函数指针支持商品中
//	// 不同项的⽐较，相对还是比较麻烦的，那么这⾥lambda就很好⽤了
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price < g2._price;
//		});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._price > g2._price;
//		});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate < g2._evaluate;
//		});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {
//		return g1._evaluate > g2._evaluate;
//		});
//	return 0;
//}
//class Rate
//{
//public:
//	Rate(double rate)
//		: _rate(rate)
//	{}
//	double operator()(double money, int year)
//	{
//		return money * _rate * year;
//	}
//private:
//	double _rate;
//};
//int main()
//{
//	double rate = 0.49;
//	// lambda
//	// 捕捉列表的rate，可以看到作为lambda_1类构造函数的参数传递了，这样要拿去初始化成员变量
//	auto r2 = [rate](double money, int year) {
//		return money * rate * year;
//		};
//	// 函数对象
//	Rate r1(rate);
//	r1(10000, 2);
//	r2(10000, 2);
//	auto func1 = [] {
//		cout << "hello world" << endl;
//		};
//	func1();
//	return 0;
//}

//
//template <class T>
//class function; // undefined
//template <class Ret, class... Args>
//class function<Ret(Args...)>;
//
//simple(1)
//template <class Fn, class... Args>
///* unspecified */ bind(Fn&& fn, Args&&... args);
//with return type(2)
//template <class Ret, class Fn, class... Args>
///* unspecified */ bind(Fn && fn, Args&&... args);


//#include<functional>
//int f(int a, int b)
//{
//	return a + b;
//}
//struct Functor
//{
//public:
//	int operator() (int a, int b)
//	{
//		return a + b;
//	}
//};
//class Plus
//{
//public:
//	Plus(int n = 10)
//		:_n(n)
//	{}
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//	double plusd(double a, double b)
//	{
//		return (a + b) * _n;
//	}
//private:
//	int _n;
//};
//int main()
//{
//	// 包装各种可调⽤对象
//	function<int(int, int)> f1 = f;
//	function<int(int, int)> f2 = Functor();
//	function<int(int, int)> f3 = [](int a, int b) {return a + b; };
//	cout << f1(1, 1) << endl;
//	cout << f2(1, 1) << endl;
//	cout << f3(1, 1) << endl;
//
//	// 包装静态成员函数
//	// 成员函数要指定类域并且前⾯加&才能获取地址
//	function<int(int, int)> f4 = &Plus::plusi;
//	cout << f4(1, 1) << endl;
//
//	// 包装普通成员函数
//	// 普通成员函数还有⼀个隐含的this指针参数，所以绑定时传对象或者对象的指针过去都可以
//	function<double(Plus*, double, double)> f5 = &Plus::plusd;
//	Plus pd;
//	cout << f5(&pd, 1.1, 1.1) << endl;
//
//	function<double(Plus, double, double)> f6 = &Plus::plusd;
//	cout << f6(pd, 1.1, 1.1) << endl;
//
//	function<double(Plus&&, double, double)> f7 = &Plus::plusd;
//	cout << f7(move(pd), 1.1, 1.1) << endl;
//	cout << f7(Plus(), 1.1, 1.1) << endl;// 也可以传匿名对象
//	return 0;
//}



#include<functional>
//#include<map>
//#include<stack>
//using namespace std;
//// 使⽤map映射string和function的⽅式实现
//// 这种⽅式的最⼤优势之⼀是⽅便扩展，假设还有其他运算，我们增加map中的映射即可
//class Solution {
//public:
//	int evalRPN(vector<string>& tokens) {
//		stack<int> st;
//		// function作为map的映射可调⽤对象的类型
//		map<string, function<int(int, int)>> opFuncMap = {
//		{"+", [](int x, int y) {return x + y; }},
//		{"-", [](int x, int y) {return x - y; }},
//		{"*", [](int x, int y) {return x * y; }},
//		{"/", [](int x, int y) {return x / y; }}
//		};
//		for (auto& str : tokens)
//			if (opFuncMap.count(str)) // 操作符
//			{
//				int right = st.top();
//				st.pop();
//				int left = st.top();
//				st.pop();
//				int ret = opFuncMap[str](left, right);// <--核心代码
//				st.push(ret);
//			}
//			else
//				st.push(stoi(str));
//		return st.top();
//	}
//};


#include<functional>
using placeholders::_1;
using placeholders::_2;
using placeholders::_3;
int Sub(int a, int b)
{
	return (a - b) * 10;
}
int SubX(int a, int b, int c)
{
	return (a - b - c) * 10;
}
class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}
	double plusd(double a, double b)
	{
		return a + b;
	}
};
int main()
{
	auto sub1 = bind(Sub, _1, _2);
	cout << sub1(10, 5) << endl;
	// bind 本质返回的⼀个仿函数对象
	// 调整参数顺序（不常用）
	// _1代表第一个实参
	// _2代表第二个实参
	// ...
	auto sub2 = bind(Sub, _2, _1);
	cout << sub2(10, 5) << endl;
	// 调整参数个数 （常用）
	auto sub3 = bind(Sub, 100, _1);
	cout << sub3(5) << endl;
	auto sub4 = bind(Sub, _1, 100);
	cout << sub4(5) << endl;
	// 分别绑死第123个参数
	auto sub5 = bind(SubX, 100, _1, _2);
	cout << sub5(5, 1) << endl;
	auto sub6 = bind(SubX, _1, 100, _2);
	cout << sub6(5, 1) << endl;
	auto sub7 = bind(SubX, _1, _2, 100);
	cout << sub7(5, 1) << endl;
	// 成员函数对象进行绑死，就不需要每次都传递了
	function<double(Plus&&, double, double)> f6 = &Plus::plusd;
	Plus pd;
	cout << f6(move(pd), 1.1, 1.1) << endl;
	cout << f6(Plus(), 1.1, 1.1) << endl;
	// bind⼀般⽤于，绑死一些固定参数
	function<double(double, double)> f7 = bind(&Plus::plusd, Plus(), _1, _2);
	cout << f7(1.1, 1.1) << endl;

	// 计算复利的lambda
	auto func1 = [](double rate, double money, int year)->double {
		double ret = money;
		for (int i = 0; i < year; i++)
		{
			ret += ret * rate;
		}
		return ret - money;
		};
	// 绑死⼀些参数，实现出⽀持不同年化利率，不同金额和不同年份计算出复利的结算利息
	function<double(double)> func3_1_5 = bind(func1, 0.015, _1, 3);
	function<double(double)> func5_1_5 = bind(func1, 0.015, _1, 5);
	function<double(double)> func10_2_5 = bind(func1, 0.025, _1, 10);
	function<double(double)> func20_3_5 = bind(func1, 0.035, _1, 30);
	cout << func3_1_5(1000000) << endl;
	cout << func5_1_5(1000000) << endl;
	cout << func10_2_5(1000000) << endl;
	cout << func20_3_5(1000000) << endl;
	//short c = 65535; 
	//short d{ 65535 };
	//cout << c << " " << d << endl;
	return 0;
}
class A { 

public: 
	A() 
	{} 

	A(int) = delete; 
};
