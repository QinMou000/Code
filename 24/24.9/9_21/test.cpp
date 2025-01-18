#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
	map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	// key不存在->插⼊ {"insert", string()}
	dict["insert"];
	// 插⼊+修改
	dict["left"] = "左边";
	// 修改
	dict["left"] = "左边、剩余";
	// key存在->查找
	cout << dict["left"] << endl;
	for (auto& e : dict)
	{
		cout << e.first << " " << e.second << endl;
	}
	  
	dict["right"] = "右边";
	dict["right"] = "右边、权力";  
	cout << dict["right"] << endl;
	return 0;

	//map<string, int> m;
	//string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
	//				"苹果", "香蕉", "苹果", "香蕉" };
	//for(auto& e:arr)
	//{
	//	auto ret = m.find(e);
	//	if (ret == m.end())
	//		m.insert({ e, 1 });
	//	else
	//		ret->second++;
	//}

	//for (auto& e : m)
	//{
	//	cout << e.first << "有" << e.second << "个";
	//	cout << endl;
	//}

	//m.insert({ 1, "Wang" });
	//m.insert({ 2, "Qin" });
	//m.insert({ 3, "bit" });
	//m.insert(make_pair(4, "hangge"));

	//auto it = m.begin();
	//while (it != m.end())
	//{
	//	cout << it->first << " " << it->second<<" ";
	//	it->second = "dashuaibi";
	//	it++;
	//}
	//cout << endl;
	//it = m.begin();
	//while (it != m.end())
	//{
	//	cout << it->first <<" "<< it->second<<" ";
	//	it++;
	//}

}