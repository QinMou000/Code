#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace Qin
{
	class string
	{
	public:
		friend istream& operator>>(istream& in, string& s);
		friend ostream& operator<<(ostream& out, string& s);
		string(const char* str = "")//默认构造
		{
			_size = _capacity = strlen(str);
			_str = new char[_size + 1];
			strcpy(_str, str);
		}
		~string()//析构
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity;
		}
		string(const string& s)//拷贝构造
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_capacity = s._capacity;
			_size = s._size;
 		}
		string& operator=(const string& s);

		typedef char* iterator;
		//iterator
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		/////////////////////////////////////////////////////modify
		void pushback(const char& ch);
		string& operator+=(char& ch);
		string& operator+=(const char* str);
		void append(const char* str);
		void clear();
		void swap(string& str);
		char* getptr()
		{
			return _str;
		}
		/////////////////////////////////////////////////////capacity
		void reserve(size_t n);
		void resize(size_t n,char ch = '\0');
		size_t size() const;
		size_t capacity()const;
		bool empty()const;
		////////////////////////////////////////////////////access
		char& operator[](size_t x);
		const char& operator[](size_t x) const;

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};

	ostream& operator<<(ostream& out, string& s);
	istream& operator>>(istream& in, string& s);
}