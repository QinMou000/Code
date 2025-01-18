#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//
//template<size_t size = 10>
//void fun()
//{
//	cout << size;
//}
//
//int main()
//{
//
//	fun();
//	return 0;
//}
template<class T1, class T2>
class Data
{
public:
	Data() { cout << "Data<T1, T2>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

template <class T1>
class Data<T1, int>
{
public:
	Data() { cout << "Data<T1, int>" << endl; }
private:
	T1 _d1;
	int _d2;
};

template <typename T1, typename T2>
class Data <T1*, T2*>
{
public:
	Data() { cout << "Data<T1*, T2*>" << endl; }
private:
	T1 _d1;
	T2 _d2;
};

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

int main()
{
	Data<double, int> d1;
	Data<int, double> d2;
	Data<int*, int*> d3;
	Data<int&, int&> d4(1, 2);
	return 0;
}