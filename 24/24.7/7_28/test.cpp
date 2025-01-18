#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


string& reverse(string& s, int i, int j)
{
    j--;
    for (; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
    return s;
}

string reverseWords(string s) {
    for (int i = 0, j = 0; j <= s.size(); j++)
    {
        if (s[j] == ' '|| s[j] == '\0')
        {
            reverse(s, i, j);
            i = j + 1;
        }
    }
    return s;
}

//string multiply(string num1, string num2) {
//    string ans;
//    int next = 0;
//    int i = num1.size() - 1, j = num2.size() - 1;
//    for (; i >= 0 && j >= 0; i--, j--)
//    {
//        int ret1 = num1[i] - '0';
//        int ret2 = num2[j] - '0';
//        ans.push_back((ret1 * ret2) % 10 + next + '0');
//        next = (ret1 * ret2) / 10;
//    }
//    while (i > 0)
//    {
//        ans.push_back((num1[i] + next) % 10);
//        next = (num1[i] + next) / 10;
//    }
//    while (j > 0)
//    {
//        ans.push_back((num2[j] + next) % 10);
//        next = (num2[j] + next) / 10;
//    }
//    reverse(ans.begin(), ans.end());
//    return ans;
//}

string multiply(string num1, string num2)
{
    vector<int> a;
    vector<int> b;
    int n = num1.size(), m = num2.size();
    for (int i = n - 1;i >= 0;i--)
        a.push_back(num1[i] - '0');
    for (int i = m - 1; i >= 0; i--)
        b.push_back(num2[i] - '0');
    vector<int> v(m+n);
    for (int i = 0; i < num1.size(); i++)
        for (int j = 0; j < num2.size(); j++)
            v[i + j] += a[i] * b[j];
    int next = 0;
    for (int i = 0; i < v.size(); i++)
    {
        next += v[i];
        v[i] = next%10;
        next /= 10;
    }
    string ans;
    int k = v.size() - 1;
    while (k > 0 && v[k] == 0)k--;
    while (k >= 0)ans += v[k--] + '0';
    return ans;
}

int main()
{
    //string s("Let's take LeetCode contest");
    //reverseWords(s);
    //cout << s;
    string s1("123");
    string s2("456");
    cout << multiply(s1, s2);

    return 0;
}