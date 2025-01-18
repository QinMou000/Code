#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class A
{
public:
	virtual ~A()
	{
		cout << "~A()" << endl;
	}
};
class B : public A {
public:
	~B()
	{
		cout << "~B()->delete:" << _p << endl;
		delete _p;
	}
protected:
	int* _p = new int[10];
};
// 只有派⽣类Student的析构函数重写了Person的析构函数，
// 下⾯的delete对象调⽤析构函数，才能构成多态，
// 才能保证p1和p2指向的对象正确的调⽤析构函数。
int main()
{
	A* p1 = new A;
	A* p2 = new B;
	delete p1;
	delete p2;
	return 0;
}
