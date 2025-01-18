#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


//
//void reverseString(vector<char>& s) {
//
//	for (size_t i = 0,j = s.size() - 1; i < j ; i++,j--)
//	{
//		swap(s[i], s[j]);
//	}
//}

void reverse(string& s, int p, int q)
{
	for (size_t i = p,j = q - 1; i < j ; i++,j--)
	{
		swap(s[i], s[j]);
	}
}

string reverseStr(string s, int k)
{
	for (int i = 0; i < s.size(); i += 2 * k)
	{
		if (i + k <= s.size())
			reverse(s, i, i + k);
		else
			reverse(s, i, s.size());
	}
	return s;
}

//int main()
//{

	//vector<char> s;
	//s.push_back('h');
	//s.push_back('e');
	//s.push_back('l');
	//s.push_back('l');
	//s.push_back('o');
	//reverseString(s);

	//string s = "abcdefg";
	//cout<<reverseStr(s, 2);

	//int x = 10;
	//auto y = &x;
	//auto* z = &x;
	//auto& m = x;
	//cout << typeid(x).name() << endl;
	//cout << typeid(y).name() << endl;
	//cout << typeid(z).name() << endl;


//	return 0;
//}

void Teststring()
{
	string s1;				 // ����յ�string�����s1
	string s2("hello bit");  // ��C��ʽ�ַ�������string�����s2
	string s3(s2);			 // ��������s3
}



int main()
{
	int arr[] = { 1,2,3,4,5 };
	for (auto& a : arr)
		cout << a << " ";
	cout << endl;
	string str("hello world");
	for (auto& ch : str)
		cout << ch;
	cout << endl;
	cout << str.npos;
	return 0;
}