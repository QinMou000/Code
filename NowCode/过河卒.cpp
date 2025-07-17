#include <asm-generic/errno.h>
#include <iostream>
using namespace std;

int m, n, x, y;

long long dp[22][22];

bool isOK(int i, int j) {
    if (x == i && y == j) // 马本来的位置
        return false;
    else if (x != i && y != j &&
             abs(x - i) + abs(y - j) == 3) // 马能走到的位置
        return false;
    return true;
}

int main() {
    cin >> m >> n >> x >> y;
    x++;
    y++; // 细节
    dp[0][1] = 1;
    for (int i = 1; i <= m + 1; i++) // 注意棋盘范围
        for (int j = 1; j <= n + 1; j++) {
            if (isOK(i, j))
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    cout << dp[m + 1][n + 1];
    return 0;
}
// 64 位输出请用 printf("%lld")

// link : https://www.nowcoder.com/practice/cc1a9bc523a24716a117b438a1dc5706