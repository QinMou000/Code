#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;
//class Date
//{
//public:
//	Date(int year = 2024)
//		:_year(year)
//	{}
//	void Print()
//	{
//		cout << _year << endl;
//	}
//private:
//	int _year = 1;
//};
//
//int main()
//{
//	Date d1;
//	d1.Print();
//
//	return 0;
//}

//class Sum {
//public:
//    Sum()
//    {
//        _ret += _i;
//        ++_i;
//    }
//    static int get()
//    {
//        return _ret;
//    }
//private:
//    static int _i;
//    static int _ret;
//};
//
//int Sum::_i = 1;
//int Sum::_ret = 0;
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        //Sum a[n];
//        Sum* p = new Sum[n];
//        return Sum::get();
//    }
//};

//
//class A
//{
//public:
//	void Print()
//	{
//		cout << a << endl;
//	}
//private:
//	int a;
//};
//
//class B
//{
//	friend class A;
//public:
//	void fun(const A& aa)
//	{
//
//	}
//private:
//	int b = 1;
//};
//
//class C
//{
//	friend class B;
//public:
//	void fun()
//	{
//		cout << B::b << endl;
//	}
//};

class A
{
	// ÓÑÔªÉùÃ÷
	friend class B;
private:
	int _a1 = 1;
	int _a2 = 2;
};
class B
{
public :
	void func1(const A& aa)
	{
		cout << aa._a1 << endl;
		cout << _b1 << endl;
	} 
	void func2(const A& aa)
	{
		cout << aa._a2 << endl;
		cout << _b2 << endl;
	}
private:
	int _b1 = 3;
	int _b2 = 4;
};
int main()
{
	A aa;
	B bb;
	bb.func1(aa);
	bb.func2(aa);
	return 0;
}