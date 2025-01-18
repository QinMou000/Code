#define _CRT_SECURE_NO_WARNINGS 1

#include"Date.h"

int Date::GetMonthDay(int year,int month) const
{
	assert(month > 0 && month < 13);
	static int arr[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		return 29;
	}
	return arr[month];
}

bool Date::CheckDate() const
{
	if (_month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year, _month))
	{
		return false;
	}
	return true;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += day;
	}
	_day -= day;
	while (_day < 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);//剪掉的是前一个月的天数所以要先--_month再getday
	}
	return *this;
}
bool Date::operator==(const Date& d) const
{
	return d._year == _year
		&& d._month == _month
		&& d._day == _day;
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

Date Date::operator+(int day) const
{
	Date tmp = *this;
	tmp += day;
	return tmp;
}

Date Date::operator-(int day) const
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

int Date::operator-(const Date& d) const
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (max != min)
	{
		++min;
		++n;
	}
	return flag * n;
}

Date& Date::operator++()
{
	return (*this) += 1;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			return _day < d._day;
		}
	}
	return false;
}

bool Date::operator>(const Date& d) const
{
	return !((*this < d)&&(*this == d));
}