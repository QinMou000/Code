#include <climits>
#include <iostream>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

ll arr[N] = {0};
ll dp[N] = {0}; // 以当前位置为结尾 连续子数组的最大和
int n;

int main() {
    cin >> n;
    for (ll i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    dp[0] = arr[0];
    ll ans = LLONG_MIN;
    for (ll i = 1; i < n; i++) {
        // 1、前面一位的最大和 + 当前位
        // 2、自己自成一个子数组
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        // 更新结果
        ans = max(ans, dp[i]);
    }
    printf("%lld", ans);
    return 0;
}
// 64 位输出请用 printf("%lld")

// link : https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking