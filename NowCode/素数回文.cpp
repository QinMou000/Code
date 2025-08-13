#include <iostream>
#include <cmath>
#include <string>
using namespace std;

typedef long long LL;

bool isPrime(LL n) { // 判断素数
    if (n < 2) return false;
    for (LL i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

LL StrToLL(string str) { // 将字符串转化为 LL
    LL x = 0;
    for (int i = 0; i < str.size(); i++)
        x = x * 10 + str[i] - '0';
    return x;
}

string t;

int main() {
    cin >> t;
    LL len = t.size();
    string str = t;
    for (LL i = len - 2; i >= 0; i--) {
        str += t[i]; // 拼接
    }
    if (isPrime(StrToLL(str)))
        cout << "prime" << endl;
    else cout << "noprime" << endl;
}
// 64 位输出请用 printf("%lld")