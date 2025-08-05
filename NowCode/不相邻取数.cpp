#include <iostream>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10; // ?????????????????????
ll arr[N]  = {0};
ll f[N]  = {0}; // 要取当前位置时 最大结果
ll g[N]  = {0}; // 不取当前位置时 最大结果

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    f[0] = arr[0];

    for (int i = 1; i < n; i++) {
        f[i] = g[i - 1] + arr[i]; // 要选当前位置
        g[i] = max(f[i - 1], g[i - 1]); // 不选当前位置 
    }
    cout << max(f[n - 1], g[n - 1]) << endl;
}
// 64 位输出请用 printf("%lld")

// link : https://www.nowcoder.com/practice/a2be806a0e5747a088670f5dc62cfa1e