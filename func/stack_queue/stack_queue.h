#pragma once
#include<deque>

namespace Qin
{	
	template<class T,class container = deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			con.push_back(x);
		}
		void pop()
		{
			con.pop_back();
		}
		const T& top() const
		{
			return con.back();
		}
		size_t size()
		{
			return con.size();
		}
		bool empty()
		{
			return con.empty();
		}
	private:
		container con;
	};
	template<class T, class container = deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			con.push_back(x);
		}
		void pop()
		{
			con.pop_front();
		}
		const T& back()const
		{
			return con.back();
		}
		const T& front() const
		{
			return con.front();
		}
		size_t size()
		{
			return con.size();
		}
		bool empty()
		{
			return con.empty();
		}
	private:
		container con;
	};
}
