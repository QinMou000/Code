#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

bool check(ll x) {
    // 判断质数
    if (x < 2) return false; // 1 和 0 都不是质数
    for (int i = 2; i <= sqrt(x) ; i++) // 除到根号 x 即可
        if (x % i == 0) return false;
    return true;
}

int main() {
    ll a, b, t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        ll x = a * b;
        if (check(x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
// 64 位输出请用 printf("%lld")