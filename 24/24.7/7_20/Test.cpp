#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

//int main()
//{
//	int year, mon, day;
//	int Date[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };;
//	int sum = 0;
//	cin >> year >> mon >> day;
//	while (mon != 1)
//	{
//		if (mon == 3 && ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))))
//		{
//			sum+=Date[2]+1;
//		}
//		else
//			sum += Date[mon - 1];
//		--mon;
//	}
//	sum += day;
//	cout << sum << endl;
//	return 0;
//}
//
//int WhichDay(int year, int mon, int day)
//{
//	int Date[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int sum = 0;
//	while (mon != 1)
//	{
//		if (mon == 3 && ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))))
//		{
//			sum += Date[2] + 1;
//		}
//		else
//			sum += Date[mon - 1];
//		--mon;
//	}
//	sum += day;
//	return sum;
//}
//
//int main()
//{
//	int year, mon, day;
//	cin >> year >> mon >> day;
//	int ret1 = WhichDay(year, mon, day);
//	cin >> year >> mon >> day;
//	int ret2 = WhichDay(year, mon, day);
//	if (ret1 > ret2)
//		cout << ret1 - ret2;
//	else
//		cout << ret2 - ret1;
//	return 0;
////}
//#include<assert.h>
//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << "年" << _month << "月" << _day << "日" << endl;
//	}
//	Date(int year = 2024, int month = 7, int day = 17)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		if (!CheckDate())
//		{
//			cout << "非法日期:";
//			Print();
//			exit(1);
//		}
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	friend istream& operator>>(istream& in, Date& d)
//	{
//		in >> d._year >> d._month >> d._day;
//		return in;
//	}
//	bool CheckDate() const;
//	int GetMonthDay(int year, int month) const;
//	int operator-(const Date& d) const;
//	bool operator<(const Date& d) const;
//	bool operator!=(const Date& d) const;
//	Date& operator++();
//	Date& operator+=(int day);
//	Date& operator-=(int day);
//
//private:
//	int _year = 2024;
//	int _month = 7;
//	int _day = 17;
//};
//int Date::GetMonthDay(int year, int month) const
//{
//	assert(month > 0 && month < 13);
//	static int arr[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//	{
//		return 29;
//	}
//	return arr[month];
//}
//
//bool Date::CheckDate() const
//{
//	if (_month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year, _month))
//	{
//		return false;
//	}
//	return true;
//}
//
//int Date::operator-(const Date& d) const
//{
//	Date max = *this;
//	Date min = d;
//	if (max < min)
//	{
//		max = d;
//		min = *this;
//	}
//	int n = 0;
//	while (max != min)
//	{
//		++min;
//		++n;
//	}
//	return n;
//}
//
//bool Date::operator<(const Date& d) const
//{
//	if (_year < d._year)
//	{
//		return true;
//	}
//	else if (_year == d._year)
//	{
//		if (_month < d._month)
//		{
//			return true;
//		}
//		else if (_month == d._month)
//		{
//			return _day < d._day;
//		}
//	}
//	return false;
//}
//
//bool Date::operator!=(const Date& d) const
//{
//	return d._year != _year
//		|| d._month != _month
//		|| d._day != _day;
//}
//Date& Date::operator+=(int day)
//{
//	if (day < 0)
//	{
//		return *this -= day;
//	}
//	_day += day;
//	while (_day > GetMonthDay(_year, _month))
//	{
//		_day -= GetMonthDay(_year, _month);
//		++_month;
//		if (_month == 13)
//		{
//			++_year;
//			_month = 1;
//		}
//	}
//	return *this;
//}
//
//Date& Date::operator-=(int day)
//{
//	if (day < 0)
//	{
//		return *this += day;
//	}
//	_day -= day;
//	while (_day < 0)
//	{
//		--_month;
//		if (_month == 0)
//		{
//			--_year;
//			_month = 12;
//		}
//		_day += GetMonthDay(_year, _month);//剪掉的是前一个月的天数所以要先--_month再getday
//	}
//	return *this;
//}
//
//Date& Date::operator++()
//{
//	return (*this) += 1;
//}
//
//int main()
//{
//	int year, mon, day;
//	int x;
//	cin >> x;
//	day = x % 100;
//	x /= 100;
//	mon = x % 100;
//	x /= 100;
//	year = x % 10000;
//
//	Date d1(year,mon,day);
//
//	cin >> x;
//	day = x % 100;
//	x /= 100;
//	mon = x % 100;
//	x /= 100;
//	year = x % 10000;
//
//	Date d2(year, mon, day);
//
//	cout << d1 - d2;
//
//	return 0;
//}


//int WhichDay(int year, int mon, int day)
//{
//	int Date[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int sum = 0;
//	while (mon != 1)
//	{
//		if (mon == 3 && ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))))
//		{
//			sum += Date[2] + 1;
//		}
//		else
//			sum += Date[mon - 1];
//		--mon;
//	}
//	sum += day;
//	return sum;
//}
//int main()
//{
//	int Date1[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int Date2[13] = { -1,31,29,31,30,31,30,31,31,30,31,30,31 };
//	int year,n;
//	cin >> year>>n;
//	int mon = 1, day = 1;
//	if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
//	{
//		while (n > Date2[mon])
//		{
//			n -= Date2[mon];
//			mon++;
//		}
//	}
//	else
//	{
//		while (n > Date1[mon])
//		{
//			n -= Date1[mon];
//			mon++;
//		}
//	}
//	day += n;
//	cout << year << "-" << mon << "-" << day;
//	return 0;
//}

//class ClassA
//{
//
//};
//
//int main()
//{
//	ClassA* pclassa = new ClassA[5];
//
//	delete pclassa;
//}
//
//template <class T>
//T fun(T x, T y)
//{
//	return x * x + y * y;
//}
//
//int main()
//{
//	//int x = fun(1.0, 2);//!
//	int y = fun<float>(1, 2.0);
//	return 0;
//}

// 三个小时看完
// 写博客
// 复习考试！！！
// 写作业

int main()
{
	string s1("hello world");
	string::iterator it = s1.begin();
	while (it != s1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;
	cout << s1.max_size() << endl;
	cout << s1.capacity() << endl;
	return 0;
}

