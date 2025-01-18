#pragma once
#include<assert.h>
#include<iostream>
#include<vector>
using namespace std;

namespace Qin
{
	template<class T>
	struct Node
	{
		Node<T>* prev;
		T data; //不仅仅是内置类型，还有可能是自定义类型，有必要重载->
		Node<T>* next;

		Node(const T& val = T())
			:data(val)
			,prev(nullptr)
			,next(nullptr)
		{}
	};

	template<class T,class Ref,class Ptr>
	struct list_iterator
	{
		typedef list_iterator<T, Ref, Ptr> self;
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;

		typedef struct Node<T> Node;

		list_iterator(Node* node = nullptr)
			:_node(node)
		{}
		list_iterator(const self& lf)
		{
			_node = lf._node;
		}
		Ref operator*()
		{
			return _node->data;
		}
		Ptr operator->()
		{
			return &_node->data;
		}
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		self operator++(int)
		{
			self tmp(_node);
			//Node* tmp = new Node(_node->data);//自己想出来的写法哟~but有点复杂了
			_node = _node->next;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(_node);
			//Node* tmp = new Node(_node->data);//自己想出来的写法哟~but有点复杂了
			_node = _node->prev;
			return tmp;
		}
		bool operator==(const self& it)
		{
			return _node == it._node;
		}
		bool operator!=(const self& it)
		{
			return _node != it._node;
		}
		Node* _node;
	};

	template<class T>
	class list
	{
	public:
		typedef struct Node<T> Node;
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;

		void empty_init()
		{
			_phead = new Node;
			_phead->next = _phead;
			_phead->prev = _phead;
			_size = 0;
		}
		list()
		{
			empty_init();
		}
		list(int n, const T& val = T())// 一定是int否则重载就会出问题
		{
			empty_init();
			for (size_t i = 0; i < n; i++)
				push_back(val);
		}
		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			empty_init();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		list(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
				push_back(e);
		}
		void swap(list<T>& lt)
		{
			std::swap(lt._phead, _phead);
			std::swap(lt._size, _size);
		}
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}
		void clear()
		{
			auto it = begin();
			while (it != end())//删到只剩头节点为止
			{
				erase(it);
				it++;
			}
		}
		iterator insert(iterator pos,const T& val)
		{
			Node* cur = pos._node;
			Node* prev = cur->prev;
			Node* newnode = new Node(val);

			prev->next = newnode;
			newnode->prev = prev;
			cur->prev = newnode;
			newnode->next = cur;

			++_size;

			return newnode;
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* next = pos._node->next;
			Node* prev = next->prev;

			delete pos._node;

			prev->next = next;
			next->prev = prev;
			--_size;
			return next;
		}
		void push_back(const T& val)
		{
			//Node* newnode = new Node(val);
			//Node* tail = _phead->prev;

			//tail->next = newnode;
			//newnode->prev = tail;
			//newnode->next = _phead;
			//_phead->prev = newnode;
			//_size++;
			insert(begin(), val);
		}
		void pop_back()
		{
			//Node* del = _phead->prev;
			//Node* newtail = del->prev;

			//delete del;
			//_phead->prev = newtail;
			//newtail->next = _phead;
			//_size--;
			erase(--end());//最后一个节点的迭代器
		}
		size_t size()
		{
			return _size;
		}
		bool empty()
		{
			return size == 0;
		}
		iterator begin()
		{
			return _phead->next;
		}
		iterator end()
		{
			return _phead;
		}
		const_iterator begin() const
		{
			return _phead->next;
		}
		const_iterator end() const
		{
			return _phead;
		}
		T& front()
		{
			return _phead->next->data;
		}
		T& back()
		{
			return _phead->prev->data;
		}
		const T& front() const
		{
			return _phead->next->data;
		}
		const T& back() const
		{
			return _phead->prev->data;
		}
	private:
		Node* _phead;
		size_t _size;
	};

	template<class T>
	void print_container(T& con)
	{
		for (auto& e : con)
			cout << e << " ";
		cout << endl;
	}
}