#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    long long n = str.size();
    // 判断所有字符是否都相同
    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (str[0] != str[i]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << 0 << endl;
        exit(0);
    }
    // 判断该字符串是不是回文串
    int left = 0, right = n - 1;
    flag = true;
    while (left < right) {
        if (str[left] == str[right]) {
            left++;
            right--;
        } else {
            flag = false;
            break;
        }
    }
    if (flag) cout << n - 1 << endl;
    else cout << n << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")

// link : https://ac.nowcoder.com/acm/problem/214851