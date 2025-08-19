#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int ans = 1;
        while (ans - 1 <= n) ans *= 2; // 找规律
        cout << ans / 2 - 1 << endl;
    }
}
// 64 位输出请用 printf("%lld")
