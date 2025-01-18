#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//
class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
	void func5() { cout << "Base::func5" << endl; }
protected:
	int a = 1;
};
class Derive : public Base
{
public:
	// 重写基类的func1
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func1" << endl; }
	void func4() { cout << "Derive::func4" << endl; }
protected:
	int b = 2;
};
int main()
{
	Base b;
	Derive d;
	return 0;
}


//int main()
//{
//	int i = 0;
//	static int j = 1;
//	int* p1 = new int;
//	const char* p2 = "xxxxxxxx";
//	printf("栈:%p\n", &i);
//	printf("静态区:%p\n", &j);
//	printf("堆:%p\n", p1);
//	printf("常量区:%p\n", p2);
//	Base b;
//	Derive d;
//	Base* p3 = &b;
//	Derive* p4 = &d;
//	printf("Person虚表地址:%p\n", *(int*)p3);
//	printf("Student虚表地址:%p\n", *(int*)p4);
//	printf("虚函数地址:%p\n", &Base::func1);
//	printf("普通函数地址:%p\n", &Base::func5);
//	return 0;
//}
//运⾏结果：
//栈 : 010FF954
//静态区 : 0071D000
//堆 : 0126D740
//常量区 : 0071ABA4
//Person虚表地址 : 0071AB44
//Student虚表地址 : 0071AB84
//虚函数地址 : 00711488
//普通函数地址 : 007114BF




#if 0
class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "买票-打折" << endl; }
};
class Soldier : public Person {
public:
	virtual void BuyTicket() { cout << "买票-优先" << endl; }
};
void Func(Person* ptr)
{
	// 这⾥可以看到虽然都是Person指针Ptr在调⽤BuyTicket
	// 但是跟ptr没关系，⽽是由ptr指向的对象决定的。
	ptr->BuyTicket();
}
int main()
{
	// 其次多态不仅仅发⽣在派⽣类对象之间，
	// 多个派⽣类继承基类，重写虚函数后
	// 多态也会发⽣在多个派⽣类之间。
	Person ps;
	Student st;
	Soldier sr;
	Func(&ps);
	Func(&st);
	Func(&sr);
	return 0;
}


// error C3248: “Car::Drive”: 声明为“final”的函数⽆法被“Benz::Drive”重写
class Car
{
public:
	virtual void Drive() final {}
};
class Benz :public Car
{
public:
	virtual void Drive() { cout << "Benz-舒适" << endl; }
};
int main()
{
	return 0;
}

// error C3668: “Benz::Drive”: 包含重写说明符“override”的⽅法没有重写任何基类⽅法
class Car {
public:
	virtual void Dirve()
	{}
};
class Benz :public Car {
public:
	virtual void Drive() override { cout << "Benz-舒适" << endl; }
};
int main()
{
	return 0;
}

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
// 只有派⽣类Student的析构函数重写了Person的析构函数，下⾯的delete对象调⽤析构函数，
// 才能构成多态，才能保证p1和p2指向的对象正确的调⽤析构函数。
int main()
{
	A* p1 = new A;
	A* p2 = new B;
	delete p1;
	delete p2;
	return 0;
}

class A {};
class B : public A {};
class Person {
public:
	virtual A* BuyTicket()
	{
		cout << "买票-全价" << endl;
		return nullptr;
	}
};
class Student : public Person {
public:
	virtual B* BuyTicket()
	{
		cout << "买票-打折" << endl;
		return nullptr;
	}
};
void Func(Person* ptr)
{
	ptr->BuyTicket();
}
int main()
{
	Person ps;
	Student st;
	Func(&ps);
	Func(&st);
	return 0;
}
#endif