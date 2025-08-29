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
// 通过⼀两个例⼦的模拟，我们发现，每次起始删除的下标都是 2 的次⽅。
// 根据这个规律，找到最后⼀次删除的起始位置的下标即可。