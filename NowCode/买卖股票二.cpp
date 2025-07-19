#include <iostream>
using namespace std;

int n;
int price[100005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> price[i];
    int ans = 0;
    for (int j = 0; j < n - 1; j++) {
        if (price[j] < price[j + 1]) // 将所有的递增序列全部拿到
            ans += price[j + 1] - price[j];
    }
    cout << ans;
    return 0;
}
// 64 位输出请用 printf("%lld")

// link : https://www.nowcoder.com/practice/64b4262d4e6d4f6181cd45446a5821ec