#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	void Print()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}
	Date(int year = 2024,int month = 7,int day = 17)
	{
		_year = year;
		_month = month;
		_day = day;
		if (!CheckDate())
		{
			cout << "�Ƿ�����:";
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
		out << d._year << "��" << d._month << "��" << d._day << "��" << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Date& d)
	{
		while (1)
		{
			cout << "��������ȷ������:";
			in >> d._year >> d._month >> d._day;
			if (!d.CheckDate())
			{
				cout << "�Ƿ�����:";
				d.Print();
				cout << "��������!!" << endl;
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
