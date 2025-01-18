#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

class Person
{
public:
	void fun()
	{
		cout << "Person::fun()" << endl;
	}
private:
	string name = "wangqin";
};

class Stu :public Person
{
public:
	void fun()
	{
		cout << "Stu::fun()" << endl;
	}
};

int main()
{
	cout << sizeof(Person);
	cout << endl;
	cout << sizeof(Stu);
	cout << endl;

	Person p;
	Stu s;
	p.fun();
	s.fun();


	return 0;
}