#define _CRT_SECURE_NO_WARNINGS 1

#include"BSTree.h"



int main()
{
	BSTree<int> t;
	// 常规的测试⽤例
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	// 特殊的带有双旋场景的测试⽤例
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto e : a)
	{
		t.Insert({ e });
	}

	//int a[] = { 8, 3, 1, 10, 1, 6, 4, 7, 14, 13 };
	//BSTree<int> bst;
	//for (auto e : a)
	//{
	//	bst.Insert(e);
	//	bst.InOrder();
	//}

	//for (auto e : a)
	//{
	//	bst.Erase(e);
	//	bst.InOrder();
	//}
	return 0;
}


#if 0

class A
{
public:
	int add(int a, int b){
		return a + b;
	}

};

int main()
{
	A* p = nullptr;
	cout << p->add(1, 2) << endl;
	return 0;
}
#include<iostream>
using namespace std;
class A
{
public:
	void Print()
	{
		cout << "A::Print()" << endl;
		cout << _a << endl;
	}
private:
	int _a;
};
int main()
{
	A* p = nullptr;
	p->Print();
	return 0;
}

class A1
{
public:
	virtual void fun1()
	{
		cout << "A1::void fun1()";
	}
private:
	int a1 = 1;

};
class A2
{
public:
	virtual void fun1()
	{
		cout << "A2::void fun1()";
	}
private:
	int a2 = 2;

};
class B :public A1,A2
{
public:
	virtual void fun1()
	{
		cout << "B::void fun1()";
	}
	virtual void fun2()
	{
		cout << "B::void fun2()";
	}
private:
	int b = 3;
};

int main()
{
	A1 a1;
	A2 a2;
	B b;

	A2* ptr = &b;

	return 0;
}
#endif