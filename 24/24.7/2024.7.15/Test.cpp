#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;
//
//class date
//{
//	friend ostream& operator<<(ostream& out, const date& d);
//
//public:
//
//	date& operator=(const date& d)
//	{
//		if (&d != this)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//
//	date(date& d)
//	{	
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	 //1.⽆参构造函数
//	//date()
//	//{
//	//	_year = 1;
//	//	_month = 1;
//	//	_day = 1;
//	//} 
//	//2.带参构造函数
//	//date(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	//3.全缺省构造函数
//	date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& out, const date& d)
//{
//	out << d._year << " " << d._month << " " << d._day << endl;
//	return out;
//}

//
//typedef int STDataType;
//class Stack
//{
//public :
//	Stack& operator=(const Stack& s)
//	{
//		if (this != &s)
//		{
//			memcpy(_a, s._a, sizeof(STDataType) * s._top);
//			_capacity = s._capacity;
//			_top = s._top;
//		}
//		return *this;
//	}
//	void Push(int x)
//	{
//		//……
//		_a[_top] = x;
//		_top++;
//	}
//	Stack(const Stack& s)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * s._capacity);
//		if (_a == nullptr)
//		{
//			perror("maollc is fail");
//			return;
//		}
//		memcpy(_a, s._a, sizeof(STDataType) * s._top);
//		_capacity = s._capacity;
//		_top = s._top;
//	}
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//private:
//	STDataType * _a;
//	size_t _capacity;
//	size_t _top;
//};
// //两个Stack实现队列
//class MyQueue
//{
//public :
//	//编译器默认⽣成MyQueue的构造函数调⽤了Stack的构造，完成了两个成员的初始化
//private:
//	Stack pushst;
//	Stack popst;
//};

//
//class A
//{ 
//public :
//void func()
//{
//	cout << "A::func()" << endl;
//}
//};
//typedef void(A::* PF)(); //成员函数指针类型
//int main()
//{
//	// C++规定成员函数要加&才能取到函数指针
//	PF pf = &A::func;
//	A obj;//定义ob类对象temp
//	// 对象调⽤成员函数指针时，使⽤.*运算符
//	(obj.*pf)();
//	return 0;
//}

class Date
{
public :
	Date * operator&()
	{
		 return this;
		// return nullptr;
		// return (Date*)00267011;
	}
	const Date * operator&() const
	{
		 return this;
		// return nullptr;
		// return (Date*)00267011;
	}
private:
	int _year; // 年
	int _month; // ⽉
	int _day; // ⽇
};

int main()
{
	//date d1(2024,7,15);
	//date d2(d1);
	//date d3 = d1;
	//d1.print();
	//d2.print();
	//d3.print();
	//cout << d1 << d2;
	//date d4;
	//d4 = d1;
	//cout << d4;

	//Stack s1;
	//s1.Push(1);

	//Stack s2;
	//s2 = s1;

	return 0;
}