#pragma once
#include<iostream>
#include<vector>
using namespace std;

namespace Qin
{
	template<class T>
	class less
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};
	template<class T>
	class greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template<class T,class Con = vector<T>,class Com = less<T>>
	class priority_queue
	{
	public:
		bool empty() const
		{
			return _con.empty();
		}
		size_t size() const
		{
			return _con.size();
		}
		const T& top()
		{
			return _con[0];
		}
		void Adjust_Up(int child)
		{
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[parent] < _con[child] )
				if (_com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
					break;
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			Adjust_Up(_con.size() - 1);
		}
		void Adjust_Down(int parent, int n)
		{
			int child = parent * 2 + 1;

			while (child < n)
			{
				//if (child + 1 < n && _con[child] > _con[child + 1])
				if (child + 1 < n && _com(_con[child], _con[child + 1]))
					child++;
				//if (_con[parent] > _con[child])
				if (_com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
					break;
			}
		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			Adjust_Down(0, _con.size());
		}
	private:
		Com _com;
		Con _con;
	};
}