#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

void ShowList()
{
	cout << endl;
}

template<class T, class ...Args>
void ShowList(T&& x,Args&&... args)
{
	cout << x << " ";
	ShowList(args...);
}

template<class ...Args>
void Print(Args&&... args)
{
	ShowList(args...);
}

//int main()
//{
//	double x = 2.2;
//	Print();
//	Print(1);
//	Print(1,string("xxxxx"));
//	Print(1.1, string("xxxxx"));
//
//	return 0;
//}
int main()
{

	int x;
	cin >> x;
	int i;
	for (i = 1; i < x; i++)
		if (i * i > x) break;
	int ret1 = i * i;
	int ret2 = (i - 1) * (i - 1);
	if (ret1 - x > ret2 - x) return ret2;
	else return ret1;

}