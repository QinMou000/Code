#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"

namespace Qin
{
	const size_t npos = -1;
	ostream& operator<<(ostream& out,string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();

		static char buff[256];
		int i = 0;

		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			if (i == 255)
			{
				buff[255] = '\0';
				s += buff;
				i = 0;
			}
			buff[i++] = ch;
			ch = in.get();
		}
		if (i > 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}
	void string::pushback(const char& ch)
	{ 
		if (_capacity == _size)
		{
			reserve(_capacity == 0 ? 4 : _capacity * 2);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
	}
	void string::append(const char* str)
	{
		int len = strlen(str);
		if (_capacity < len + _size)
		{
			reserve(2 * _capacity > len + _size ? 2 * _capacity: len + _size);
		}
		strcpy(_str + _size, str);
		_size += len;
	}
	string& string::operator+=(char& ch)
	{
		pushback(ch);
		return *this;
	}
	string& string::operator+=(const char* str)
	{
		append(str);
		return *this;
	}
	string& string::operator=(const string& s)
	{
		if (&s != this)
		{
			delete[] _str;

			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_capacity = s._capacity;
			_size = s._size;
		}
		return *this;
	}
	char& string::operator[](size_t x)
	{
		assert(x < _size);
		return _str[x];
	}
	const char& string::operator[](size_t x) const
	{
		assert(x < _size);
		return _str[x];
	}
	void string::clear()
	{
		_str[0] = '\0';
		_size = 0;
	}
	void string::swap(string& s)
	{
		std::swap(s._capacity, _capacity);
		std::swap(s._size, _size);
		std::swap(s._str, _str);
	}
	size_t string:: size() const 
	{
		return _size;
	}
	size_t string::capacity()const
	{
		return _capacity;
	}
	bool string::empty()const
	{
		return _size == 0;
	}
	void string::resize(size_t n, char ch)
	{
		*(_str + n) = ch;
		_size = n;
	}
}