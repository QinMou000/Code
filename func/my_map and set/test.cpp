#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include"My_Set.h"
#include"My_Map.h"


void Print(const Qin::set<int>& s)
{
	Qin::set<int>::const_iterator it = s.end();
	while (it != s.begin())
	{
		--it;
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	Qin::set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);
	s.insert(6);

	Qin::set<int>::iterator sit = s.begin();
	//*sit += 10;
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	Print(s);


	Qin::map<string, string> dict;
	dict.insert({ "sort", "≈≈–Ú" });
	dict.insert({ "left", "◊Û±ﬂ" });
	dict.insert({ "right", "”“±ﬂ" });

	dict["left"] = "◊Û±ﬂ£¨ £”‡";
	dict["insert"] = "≤Â»Î";
	dict["string"];

	Qin::map<string, string>::iterator it = dict.begin();
	while (it != dict.end())
	{
		// ≤ªƒ‹–ﬁ∏ƒfirst£¨ø…“‘–ﬁ∏ƒsecond
		//it->first += 'x';
		it->second += 'x';

		cout << it->first << ":" << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	return 0;
}
