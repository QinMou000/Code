#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<set>
#include<map>

using namespace std;

int main()
{
	//multiset<int> ms;
	map<string,string> m;

	pair<string, string> p = { "wang","qin" };
	m.insert(p);
	m.insert({ "tree","��" });

	auto it = m.begin();
	while (it != m.end());
	{
		cout << it->first << it->second << endl;
		it++;
	}

	return 0;
}

//int main()
//{
	//set<int> s;

	//s.insert(1);
	//s.insert(5);
	//s.insert(3);
	//s.insert(2);
	//s.insert(7);
	//s.insert(5);

	//auto it = s.begin();
	//while (it != s.end())
	//{
	//	cout << *it;
	//	++it;
	//}
	//cout << endl;


	//set<int> s = { 2,5,9,3,6,2,6 };
	//auto it = s.begin();
	//while (it != s.end())
	//{
	//	cout << *it;
	//	++it;
	//}
	//cout << endl;

	//for (auto e : s)
	//{
	//	cout << e;
	//}
	//cout << endl;

	//int x;
	//cin >> x;
	//size_t ans = s.erase(x);
	//if (ans)
	//{
	//	cout << x << "ɾ���ɹ�" << endl;
	//}
	//else
	//{
	//	cout << x << "û��" << endl;
	//}
	//int x;
	//cin >> x;
	//auto it = s.find(x);
	//if (it != s.end())
	//{
	//	s.erase(it);
	//	cout << x << "ɾ���ɹ�" << endl;
	//}
	//else
	//	cout << x << "������" << endl;

	//int x;
	//cin >> x;
	//int ret = s.count(x);
	//if (ret)
	//{
	//	cout << "����";
	//}
	//else
	//{
	//	cout << "������";
	//}

//	auto it1 = s.lower_bound(3);
//	auto it2 = s.upper_bound(6);
//	s.erase(it1, it2);
//
//	for (auto e : s)
//	{
//		cout << e;
//	}
//	cout << endl;
//}