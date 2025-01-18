#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

namespace Qin
{
	void BubbleSort(vector<int>& a)
	{
		//int n = a.size();
		//for (int i = 0; i < n; i++)
		//	for (int j = i + 1; j < n; j++)
		//		if (a[i] > a[j])
		//			swap(a[i], a[j]);
		int n = a.size();
		for (int i = n; i > 0; i--)
			for (int j = 1; j < n; j++)
				if (a[j-1] > a[j])
					swap(a[j-1], a[j]);
	}
	//插入排序
	void InsertSort(vector<int>& a)
	{
		int n = a.size();
		for (int i = 0; i < n - 1; i++)//注意i的取值
		{
			int end = i;
			int tmp = a[end + 1];
			while (end >= 0)
			{
				if (a[end] > tmp)//这里只能写tmp不能写成a[end+1](每一次循环都要改变)
				{
					a[end + 1] = a[end];
					end--;
				}
				else
					break;
			}
			a[end + 1] = tmp;
		}
	}
	//选择排序
	void SelectSort(vector<int>& a)
	{

		int start = 0;
		int end = a.size() - 1;
		while (end > start)
		{
			int mini = start;
			int maxi = end;
			for (int i = start; i <= end; i++)
			{
				if (a[mini] > a[i])
					mini = i;
				if (a[maxi] < a[i])
					maxi = i;
			}
			if (mini == end)
			{
				swap(a[maxi], a[end]);
				mini = maxi;
				swap(a[mini], a[start]);
			}
			else
			{
				swap(a[maxi], a[end]);
				swap(a[mini], a[start]);
			}
			end--;
			start++;
		}
	}
}


int main()
{
	vector<int> arr1{ 5,1,2,3,4,5,9,7,8,2 };
	Qin::BubbleSort(arr1);

	vector<int> arr2{ 5,1,2,3,4,5,9,7,8,2 };
	Qin::InsertSort(arr2);

	vector<int> arr3{ 5,1,2,3,4,5,9,7,8,2 };
	Qin::SelectSort(arr3);
	
	for (auto e : arr1)
		cout << e << " " ;
	cout << endl;
	for (auto e : arr2)
		cout << e << " " ;
	cout << endl;
	for (auto e : arr3)
		cout << e << " ";
	cout << endl;
	return 0;
}