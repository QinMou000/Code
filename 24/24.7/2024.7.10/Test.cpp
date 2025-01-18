#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

//class Date
//{
//public:
//	//Date(int year = 2024, int month = 7, int day = 10)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	void Init(int year, int month, int day);
//	void Print()
//	{
//		cout << _year << "/" << _month << "/"<< _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Date::Init(int year, int month, int day)
//{
//	_year = year;
//	_month = month;
//	_day = day;
//}
//
//class Stack
//{
//public:
//	Stack()
//	{
//		_a = (int*)malloc(sizeof(int) * 4);
//		if (_a == nullptr)
//		{
//			perror("malloc is fail");
//			return;
//		}
//		_capacity = 4;
//		_top = 0;
//	}
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//
//private:
//	int* _a;
//	int _capacity;
//	int _top;
//};
//
//class Queue
//{
//public:
//
//private:
//	Stack S1;
//	Stack S2;
//};
//
//class A
//{
//
//};
//
//class B
//{
//public:
//	void print()
//	{
//
//	}
//};

#include<iostream>
#include<cassert>
using namespace std;
typedef int STDataType;
class Stack
{
public :
	// 成员函数
	void Init(int n = 4)
	{
		_a = (STDataType*)malloc(sizeof(STDataType) * n);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败");
			return;
		} 
		_capacity = n;
		_top = 0;
	}
	void Push(STDataType x)
	{
		if (_top == _capacity)
		{
			int newcapacity = _capacity * 2;
			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
				sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}
			_a = tmp;
			_capacity = newcapacity;
		} 
			_a[_top++] = x;
	}
	void Pop()
	{
		assert(_top > 0);
		--_top;
	}
	bool Empty()
	{
		return _top == 0;
	} 
	int Top()
	{
		assert(_top > 0);
		return _a[_top - 1];
	} 
	void Destroy()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}
private:
	// 成员变量
	STDataType* _a;
	size_t _capacity;
	size_t _top;
};
int main()
{
	//Date d1;
	//Date d2;

	//d1.Init(2024, 7, 10);
	//d1.Print();
	//d2.Init(2024, 7, 11);
	//d2.Print();

	Stack s1;
	s1.Init();


	return 0;
}