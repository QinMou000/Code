#include <iostream>
using namespace std;

typedef long long ll;

ll q, x;
ll check(ll x) {
    // 判断 x 本身是否为偶数
    if (x % 2 == 0) return x;
    // 判断 x 中是否有一个位数是偶数 将其放置最后
    string s;
    char ch;
    bool flag = false;
    ll tmp = x;
    while (tmp) {
        s.push_back(tmp % 10 + '0');
        tmp /= 10;
    }
    for (int i = 0; i < s.size(); i++) {
        if (ll(s[i] - '0') % 2 == 0) { // 需要强转一下
            ch = s[i];
            s.erase(i, 1);
            s.push_back(ch);
            flag = true;
            break;
        }
    }
    if (flag)
        return stoi(s);
    return -1;
}


int main() {
    cin >> q;
    while (q--) {
        cin >> x;
        ll ans = check(x);
        cout << ans << endl;
    }
}
// 64 位输出请用 printf("%lld")