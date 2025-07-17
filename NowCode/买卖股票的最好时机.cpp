#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
    cin >> n;
    vector<int> price(n);
    for (auto& e : price)
        cin >> e;
    int prevMin = INT_MAX;
    int ans = 0;
    for (int i = 0; i < n; i++) { // 以当前位置为卖出点 去找买入点
        ans  = max(ans, price[i] - prevMin); // 更新结果 最小买入点
        prevMin = min(price[i], prevMin); // 将当前位置和前面最小值比较
    }
    cout << ans;
}
// 64 位输出请用 printf("%lld")

// link : https://www.nowcoder.com/practice/64b4262d4e6d4f6181cd45446a5821ec