#include <iostream>
using namespace std;

int main() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    // 暴力枚举 类似的题都可以暴力
    long long ans = 0; // 关键是范围
    for (long long x = 0; x <= min(2 / n, m); x++) { // 一号礼包个数
        // 根据剩下的水果决定二号礼包个数
        long long y = min(n - 2 * x, (m - x) / 2);
        ans = max(ans, a * x + b * y);
    }
    cout << ans << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")

// link : https://www.nowcoder.com/practice/fa0519c4469f4241bbdb7eabe7e3b295
