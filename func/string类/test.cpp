#define _CRT_SECURE_NO_WARNINGS 1

#include"string.h"
namespace Qin
{
	void Test1()
	{
		string s1("abcd");
		cout << s1.getptr() << endl;
		string s2 = s1;
		cout << s2.getptr() << endl;
		cout << s2 << endl;

		cout << s2[3] << endl;

		string s3;
		s3.pushback('a');
		cout << s3 << endl;
	}
	void Test2()
	{
		string s1("hello");
		cin >> s1;
		cout << s1 << endl;
		s1.resize(2);
		cout << s1;
	}
}

int main()
{
	//Qin::Test1();
	Qin::Test2();
	return 0;
}

