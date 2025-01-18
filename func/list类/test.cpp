#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

namespace Qin
{
	class A
	{
	public:
		int a1 = 1;
		int a2 = 2;
	};

	void test_list1()
	{
		list<int> lt;  //新建一个链表

		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		print_container(lt);
		lt.pop_back();
		lt.pop_back();
		print_container(lt);

		list<int>::iterator it = lt.begin();

		cout << it.operator->() << endl;
		cout << it.operator*() << endl;
		/****************************************************************/
		list<A> lta;  //新建一个链表
		lta.push_back(A());
		lta.push_back(A());
		lta.push_back(A());
		lta.push_back(A());

		list<A>::iterator ita = lta.begin();
		cout << ita->a1 << " " << ita->a2 << endl;
	}
	void test_list2()
	{
		list<int> lt1(3,2);  //新建一个链表
		print_container(lt1);
		//list<int>::const_iterator it = lt1.begin();


		//list<int>::iterator first = lt1.begin();
		//list<int>::iterator last = lt1.end();
		//list<int> lt2(first, last);  //新建一个链表
		//print_container(lt2);


		//list<int> lt3(lt1);  //新建一个链表
		//print_container(lt3);

		//list<int> lt4;  //新建一个链表
		//lt4 = lt1;
		//print_container(lt4);


		cout << lt1.back();
		cout << lt1.front();
		list<int>::iterator it = lt1.begin();

		lt1.insert(it, 1);
		print_container(lt1);
		lt1.clear();

	}
}
#include<list>
int main()
{
	//Qin::test_list2();

	list<int> lt({ 1,2 });
	auto end = lt.end();
	--end;
	auto it = lt.erase(end);
	cout << *it;
	return 0;
}