#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
class Date
{
public:
	bool operator<(const Date& d1)
	{
		return true;
	}
private:
};


template<class T>
bool Less(T left, T right)
{
	return left < right;
}
template<>
bool Less<Date*>(Date* left, Date* right)
{
	return *left < *right;
}

/*************************************************/

template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//两个参数偏特化为指针类型
template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};
//两个参数偏特化为引用类型
template <typename T1, typename T2>
class Data <T1&, T2&>
{
public:
	Data(const T1& d1, const T2& d2)
		: _d1(d1)
		, _d2(d2)
	{
		cout << "Data<T1&, T2&>" << endl;
	}
private:
	const T1& _d1;
	const T2& _d2;
};