#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;

template<class Container>
void fun(Container)
{
	Container cont = { 1, 2, 3, 4, 5 };

	for (auto iter = cont.begin(); iter != cont.end();)
	{
		auto tempIt = iter;
		++iter;
		cont.erase(tempIt);
	}
}

class add
{
public:
	int operator()(int a,int b)
	{
		return a + b;
	}
};

//int main()
//{
//	cout << add()(1, 2);
//

	//list<int> lt;
	//vector<int> v;
	//deque<int> d;
	//fun(lt);

	//priority_queue<int, vector<int>, less<int>> q;
	//q.emplace(1);
	//q.emplace(5);
	//q.emplace(3);
	//q.emplace(2);
	//q.emplace(4);
	//while (!q.empty())
	//{
	//	cout << q.top();
	//	q.pop();
	//}
	//cout << endl;
	//priority_queue<string> b;
	//b.push("abc");
	//b.push("abcd");
	//b.push("cbd");
	//while (!b.empty())
	//{
	//	cout << b.top() << ' ';
	//	b.pop();
	//}
	//cout << endl;
//	return 0;
//}

//#include <vector>
//#include <queue>
//#include <functional> // greater算法的头文件
//void TestPriorityQueue()
//{
//	// 默认情况下，创建的是大堆，其底层按照小于号比较
//	vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
//	priority_queue<int> q1;
//	for (auto& e : v)
//		q1.push(e);
//	cout << q1.top() << endl;
//	// 如果要创建小堆，将第三个模板参数换成greater比较方式
//	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
//	cout << q2.top() << endl;
//}


//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	: _year(year)
//	, _month(month)
//	, _day(day)
//	{}
//	bool operator<(const Date& d)const
//	{
//		return (_year < d._year) ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == d._month && _day < d._day);
//	}
//	bool operator>(const Date& d)const
//	{
//		return (_year > d._year) ||
//			(_year == d._year && _month > d._month) ||
//			(_year == d._year && _month == d._month && _day > d._day);
//	}
//	friend ostream& operator<<(ostream& _cout, const Date& d)
//	{
//		_cout << d._year << "-" << d._month << "-" << d._day;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void testpriorityqueue()
//{
//	// 大堆，需要用户在自定义类型中提供<的重载
//	priority_queue<Date> q1;
//	q1.push(Date(2018, 10, 29));
//	q1.push(Date(2018, 10, 28));
//	q1.push(Date(2018, 10, 30));
//	cout << q1.top() << endl;
//	// 如果要创建小堆，需要用户提供>的重载
//	priority_queue<Date, vector<Date>, greater<Date>> q2;
//	q2.push(Date(2018, 10, 29));
//	q2.push(Date(2018, 10, 28));
//	q2.push(Date(2018, 10, 30));
//	cout << q2.top() << endl;
//}
//
//#include<deque>
//namespace Qin
//{
//	template<class T, class Con = deque<T>>
//	//template<class T, class Con = vector<T>>
//	//template<class T, class Con = list<T>>
//	class stack
//	{
//	public:
//		stack() {}
//		void push(const T& x) { _c.push_back(x); }
//		void pop() { _c.pop_back(); }
//		T& top() { return _c.back(); }
//		const T& top()const { return _c.back(); }
//		size_t size()const { return _c.size(); }
//		bool empty()const { return _c.empty(); }
//	private:
//		Con _c;
//	};
//}
//
//#include<deque>
//#include <list>
//namespace bite
//{
//	template<class T, class Con = deque<T>>
//	//template<class T, class Con = list<T>>
//	class queue
//	{
//	public:
//		queue() {}
//		void push(const T& x) { _c.push_back(x); }
//		void pop() { _c.pop_front(); }
//		T& back() { return _c.back(); }
//		const T& back()const { return _c.back(); }
//		T& front() { return _c.front(); }
//		const T& front()const { return _c.front(); }
//		size_t size()const { return _c.size(); }
//		bool empty()const { return _c.empty; }
//	private:
//		Con _con;
//	};
//}
//
//
//int main()
//{
//	//testpriorityqueue();
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	// 请在此输入您的代码
//	int t, a, b, c;
//	cin >> t;
//	cin >> a >> b >> c;
//	int day = 0;
//	int x = a;
//	while (x < b)
//	{
//		if ((x + 2) % c != 0)
//		{
//			x += 2;
//		}
//		else if ((x + 1) % c != 0)
//		{
//			x += 1;
//		}
//		day++;
//	}
//	cout << day;
//	return 0;
//}

int main()
{
	// 请在此输入您的代码

	int n, k;
	cin >> n >> k;
	int x = n - k;
	int ans = 0;
	for (x = n - k; x > k; x--)
	{
		int N = n;
		while (N > k)
		{
			N -= x;
			if (N == k)
			{
				ans++;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
