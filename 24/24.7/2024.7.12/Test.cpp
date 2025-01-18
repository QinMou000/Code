#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

class Date {

public:
	void Print() const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	Date(int year = 2024,int month = 7,int day = 12)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//Date(const Date& d)//没有必要写，没有外空间，直接可以用编译器生成的默认浅拷贝构造
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	bool operator==(const Date& d)
	{
		if (_year == d._year &&_month == d._month &&_day == d._day)
			return true;
		return false;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()//全是技巧，全是细节
{
	Date d1;
	Date d2 = d1;

	d1.Print();
	d2.Print();

	//Date* const this;
	//const Date* this;

	return 0;
} 
//
//#include <stdio.h>
//
//void test1()
//{
//    int n = 10;
//    int m = 20;
//    int* p = &n;
//    *p = 20;//ok?
//    p = &m; //ok?
//}
//void test2()
//{
//    int n = 10;
//    int m = 20;
//    const int* p = &n;
//    *p = 20;//ok?
//    p = &m; //ok?
//}
//void test3()
//{
//    int n = 10;
//    int m = 20;
//    int* const p = &n;
//    *p = 20; //ok?
//    p = &m; //ok?
//}
//void test4()
//{
//    int n = 10;
//    int m = 20;
//    int const* const p = &n;
//    *p = 20; //ok?
//    p = &m; //ok?
//}
//int main()
//{
//    //测试⽆const修饰的情况
//    test1();
//    //测试const放在*的左边情况
//    test2();
//    //测试const放在*的右边情况
//    test3();
//    //测试*的左右两边都有const
//    test4();
//    return 0;
//}