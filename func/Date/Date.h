#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}
	Date(int year = 2024,int month = 7,int day = 17)
	{
		_year = year;
		_month = month;
		_day = day;
		if (!CheckDate())
		{
			cout << "非法日期:";
			Print();
			exit(1);
		}
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	friend ostream& operator<<(ostream& out, const Date& d)
	{
		out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Date& d)
	{
		while (1)
		{
			cout << "请输入正确的日期:";
			in >> d._year >> d._month >> d._day;
			if (!d.CheckDate())
			{
				cout << "非法日期:";
				d.Print();
				cout << "重新输入!!" << endl;
			}
			else
			{
				break;
			}
		}
		return in;
	}
	bool CheckDate() const;
	int GetMonthDay(int year,int month) const;
	Date& operator+=(int day);
	Date& operator-=(int day);
	Date operator+(int day) const;
	int operator-(const Date& d) const;
	Date operator-(int day) const;
	bool operator<(const Date& d) const;
	Date& operator++();
	Date operator++(int);
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	bool operator>(const Date& d) const;
private:
	int _year = 2024;
	int _month = 7;
	int _day = 17;
};
