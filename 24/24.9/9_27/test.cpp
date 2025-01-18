#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<map>
#include<set>

using namespace std;

int main()
{
	//set<int,greater<int>> s = { 1,2 ,3,4 };

	// cout << s[0] << endl;//set没有重载[]

	//map<int, int> m;

	multimap<int, int> mm = { {1,2},{1,3},{1,4} };

 
	return 0;
}


//// empty(1) ⽆参默认构造
//explicit set(const key_compare & comp = key_compare(),
//	const allocator_type & alloc = allocator_type());
//// range (2) 迭代器区间构造
//template <class InputIterator>
//set(InputIterator first, InputIterator last,
//	const key_compare& comp = key_compare(),
//	const allocator_type & = allocator_type());
//// copy (3) 拷⻉构造
//set(const set& x);
//// initializer list (5) initializer 列表构造
//set(initializer_list<value_type> il,
//	const key_compare& comp = key_compare(),
//	const allocator_type& alloc = allocator_type());
//// 迭代器是⼀个双向迭代器
//iterator->a bidirectional iterator to const value_type
//// 正向迭代器
//iterator begin();
//iterator end();
//// 反向迭代器
//reverse_iterator rbegin();
//reverse_iterator rend();