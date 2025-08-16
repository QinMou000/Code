#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e3 + 10;

int dp[N][N] = { 0 };
string s, t;

int main() {
    // 二维 dp 问题
    cin >> s >> t;
    int slen = s.size();
    int tlen = t.size();

    for (int i = 1; i <= slen; i++) {
        dp[i][0] = i; // 初始化 bro
        for (int j = 1; j <= tlen; j++) {
            dp[0][j] = j;
            if (s[i - 1] == t[j - 1]) // 注意 i j 不要写错了！！！
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
        }
    }

    // for (int i = 1; i <= slen; i++) {
    //     for (int j = 1; j <= tlen; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[slen][tlen] << endl;
}