#include <iostream>
using namespace std;

int m, n;
char s1[1010];
char s2[1010];
// dp[i][j] 表示到 s1[i] 和 s2[j] 为止 两个字符串的最长公共子序列
int dp[1010][1010] = { 0 };

int main() {
    cin >> n >> m;
    cin >> s1 >> s2;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            // 两种情况
            // 因为多加一行一列 注意下表映射
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    cout << dp[n][m] << endl;
}
// 64 位输出请用 printf("%lld")