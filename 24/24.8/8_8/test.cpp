#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	auto it = l.begin();
	auto rit = l.rbegin();

	while (it != l.end())
	{
		cout << *it;
		it++;
	}
	cout << endl;
	while (rit != l.rend())
	{
		cout << *rit;
		rit++;
	}
	cout << endl;
	cout << *(l.rbegin()) << endl;
	cout << *(l.end()) << endl;

	return 0;
}
