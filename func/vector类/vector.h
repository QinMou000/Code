#pragma once
#include<string.h>
#include<assert.h>
#include<iostream>
#include<string.h>
#include<string>
#include<list>

using namespace std;

namespace Qin
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
		{}
		vector(const vector<T>& v)
		{
			//swap(v);//��Ҫ��const
			reserve(v.capacity());
			for (auto& e : v)
			push_back(e);
		}
		template<class inputiterator>//�������������͵ĵ�����
		// ��ģ��ĳ�Ա�����������Լ����Ǻ���ģ��
		vector(inputiterator first, inputiterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		vector(int n, const T& val = T())
		{
			reserve(n);
			while (n--)
				push_back(val);
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_shorage = nullptr;
			}
		}
		void swap(vector<T>& v)
		{
			std::swap(_finish, v._finish);
			std::swap(_start, v._start);
			std::swap(_end_of_shorage, v._end_of_shorage);
		}
		void clear()
		{
			_start = _finish;
		}
		vector<T>& operator=(vector<T> v)
		{
			//if (this != &v)
			//{
			//	clear();
			//	reserve(v.capacity());
			//	for (auto& e : v)
			//		push_back(e);
			//}
			swap(v);
			return *this;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T* tmp = new T[n];
				//memcpy(tmp, _start, size() * sizeof(T));
				//for (size_t i = 0; i < size(); i++)
				//{
				//	tmp[i] = _start[i]// ���victor������string�������ֵ���õ���string�ĸ�ֵ���أ������Լ����¿ռ�
				//}
				size_t x = size();
				while (x--)
					tmp[x] = _start[x];

				delete[] _start;

				_finish = size() + tmp;// һ��Ҫ�ȸ�finish����start����size()�����finishʧЧ������
				_start = tmp;
				_end_of_shorage = tmp + n;
			}
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _end_of_shorage - _start;
		}
		void push_back(const T& x)
		{
			if (_finish == _end_of_shorage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			(*_finish) = x;
			++_finish;
		}
		T& operator[](size_t n)
		{
			assert(n < size());
			return _start[n];
		}
		const T& operator[](size_t n) const
		{
			assert(n < size());
			return _start[n];
		}
		bool empty()const
		{
			return _finish == _start;
		}
		void pop_back()
		{
			assert(!empty());
			--_finish;
		}
		iterator insert(iterator pos,const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _end_of_shorage)
			{
				int ret = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + ret;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			++_finish;
			return pos;
		}
		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
		}
		void resize(size_t n,T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}
		//iterator find(iterator start, iterator end,const T& x)
		//{
		//	iterator ret = start;
		//	while (ret != end)
		//	{
		//		if (*ret == x)
		//			return ret;
		//		ret++;
		//	}
		//	return nullptr;
		//}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_shorage = nullptr;
	};

	template<class container>
	void print_container(const container& v)
	{
		for (auto t : v)
			cout << t<< ' ';
		cout << endl;
	}
}
