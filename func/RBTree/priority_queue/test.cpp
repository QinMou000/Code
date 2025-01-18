#define _CRT_SECURE_NO_WARNINGS 1
#include"priority_queue.h"

int main()
{

	Qin::priority_queue<int> pri;
	pri.push(2);
	pri.push(1);
	pri.push(3);
	pri.push(6);
	pri.push(5);
	while (!pri.empty())
	{
		cout << pri.top();
		pri.pop();
	}

#if 0
	vector<int> v;
	for (int i = 0; i <= 6; i++)
		v.push_back(i);
	for(auto e : v)
	{
		cout << e;
		v.pop_back();
	}
#endif
	return 0;
}