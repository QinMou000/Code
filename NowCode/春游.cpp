#include <iostream>
using namespace std;

typedef long long LL;
LL T;
LL n, a, b;

LL func() {
    LL ans = 0;
    if (n <= 2) return min(a, b);
    if (3 * a < 2 * b) { // 如果双人船的人均单价小于三人船
        ans += n / 2 * a;
        if (n % 2 != 0)  // 多出一个人的情况
            ans += min(a, min (b,  b - a));
    } else {// 如果双人船的人均单价大于三人船
        ans += n / 3 * b;
        if (n % 3 == 1)  // 多出一个人的情况
            ans += min(a, min(b, 2 * a - b));
        else if (n % 3 == 2)  // 多出两个人的情况
            ans += min(a, min(b, 3 * a - b));
    }
    return ans;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        cout << func() << endl;;
    }
    return 0;
}