#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//
//int myAtoi(string str)
//{
//	int flag = 1;
//	int ans = 0;
//	int len = str.size();
//	if (len == 0)
//		return 0;
//	int i = 0;
//	while (str[i] == ' ')
//		if (++i == len)
//			break;
//	if (str[i] == '-')
//		flag = -1;
//	if (str[i] == '-' || str[i] == '+')
//		++i;
//	for (size_t j = i; j < len; j++)
//	{
//		if (str[j] < '0' || str[j]>'9')
//			break;
//		if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && str[j] > '7'))
//			return flag == 1 ? INT_MAX : INT_MIN;
//		ans = ans * 10 + (str[j] - '0');
//	}
//	return ans * flag;
//}

string addStrings(string num1, string num2)
{
	int end1 = num1.size() - 1;
	int end2 = num2.size() - 1;
	string ans;
	ans.reserve(max(end1,end2)+1);
	int next = 0;
	while (end1 >= 0 || end2 >= 0)
	{
		int val1 = end1 < 0 ? 0 : num1[end1] - '0';
		int val2 = end2 < 0 ? 0 : num2[end2] - '0';
		int ret = val1 + val2 + next;
		ans.push_back((ret % 10) + '0');
		next = ret / 10;
		--end1;
		--end2;
	}
	if (next == 1)
		ans += '1';
	reverse(ans.begin(), ans.end());
	return ans;
}
/*
string addStrings(string num1, string num2) {
	int end1 = num1.size() - 1;
	int end2 = num2.size() - 1;
	//进位
	int next = 0;
	//提前开好空间
	string ans;
	ans.reserve(num1.size() > num2.size() ? num1.size() + 1 : num2.size() + 1);
	//当num1和num2都加完，循环结束
	while (end1 >= 0 || end2 >= 0)
	{
		//用char减去‘0’，得到int值，若该位不存在则为0
		int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
		int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
		//相加
		int sum = val1 + val2 + next;
		next = sum / 10;
		sum = sum % 10;
		//将该位相加的结果存到ans字符串中
		ans += ('0' + sum);
		//更新end1、end2
		--end1;
		--end2;
	}
	if (next == 1)
	{
		ans += ('1');
	}
	//此时ans字符串是倒序的，需要翻转一次
	reverse(ans.begin(), ans.end());
	return ans;
}*/

int main()
{
	string s1("11");
	string s2("123");
	string ans = addStrings(s1, s2);
	cout << ans << endl;
	//const char* s("-91283472332");
	//cout << myAtoi(s) << endl;

	//string strText = "How are you?";
	//string strSeparator = " ";
	//string strResult;
	//int size_pos = 0;
	//int size_prev_pos = 0;
	//while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)
	//{
	//	strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
	//	cout << strResult << " ";
	//	size_prev_pos = ++size_pos;
	//}
	//if (size_prev_pos != strText.size())
	//{
	//	strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);
	//	cout << strResult << " ";
	//}
	//cout << endl;	
	return 0;
}

