#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str); // 不能用 cin 会忽略空格
    // 先将整个字符串翻转
    reverse(str.begin(), str.end());
    int left = 0, right = 0;
    int n = str.size();
    // 针对一个单词进行翻转
    while (left < n) {
        right = left;
        while (right < n && str[right] != ' ') right++;
        reverse(str.begin() + left, str.begin() + right); // 左闭右开区间

        while (right < n && str[right] == ' ') right++; // 跳过空格
        left = right;
    }
    cout << str;
}
// 64 位输出请用 printf("%lld")

// link : https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&ru=/exam/oj