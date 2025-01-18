#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//int removeDuplicates(vector<int>& nums) {
//	auto it = nums.begin();
//	while(it != nums.end() - 1)
//	{
//		auto next = it + 1;
//		while (*it == *next)
//		{
//			next = nums.erase(next);
//			if (next - nums.begin() > nums.size() - 1)
//				break;
//		}
//		it++;
//	}
//	return nums.size();
//}
//
//int removeDuplicates(vector<int>& nums) {
//	int fast = 1,slow = 0;
//	while (fast < nums.size())
//	{
//		if (nums[fast] != nums[slow])
//		{
//			slow++;
//			nums[slow] = nums[fast];
//		}
//		if (nums[fast] == nums[slow])
//			fast++;
//	}
//	return slow + 1;
//}

//int MoreThanHalfNum_Solution(vector<int>& numbers) {
//    // write code here
//    sort(numbers.begin(), numbers.end());
//    return numbers[numbers.size() / 2];
//}
//
//int main()
//{
//	//vector<int> v({ 1,1,2 });
//	//cout<<removeDuplicates(v);
//	//return 0;
//
//
//	vector<int> v({ 1,1,2 ,2});
//	cout<<MoreThanHalfNum_Solution(v);
//	return 0;
//
//}
#include<list>
//template<class T>
//void removeDuplicates(list<T>& aList)
//{
//	T curValue;
//	list<T>::iterator cur, p;
//	cur = aList.begin();
//	while (cur != aList.end())
//	{
//		curValue = *cur;
//		//¿Õ°×ÐÐ 1
//		p = ++cur;
//		while (p != aList.end())
//		{
//			if (*p == curValue)
//			{
//				//¿Õ°×ÐÐ 2
//				aList.erase(p);
//			}
//			else
//			{
//				p++;
//			}
//		}
//	}
//}
//
//
//int main()
//{
//	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
//	int n = sizeof(ar) / sizeof(int);
//	vector<int> v(ar, ar + n);
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it != 0)
//			cout << *it;
//		else
//			v.erase(it);
//		it++;
//	}
//	return 0;
//
//}
int main()
{
	//           4  3 2 1 0    9 8 7 6 5
	int ar[] = { 0,1, 2, 3, 4,  5, 6, 7, 8, 9 };
	int n = sizeof(ar) / sizeof(int);//10
	list<int> mylist(ar, ar + n);
	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);
	reverse(mylist.begin(), pos);
	reverse(pos, mylist.end());
	list<int>::const_reverse_iterator crit = mylist.crbegin();
	while (crit != mylist.crend())
	{
		cout << *crit << " ";
		++crit;
	}
	cout << endl;
}