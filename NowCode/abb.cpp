#include <iostream>
using namespace std;

typedef long long LL;

const int N = 1e5 + 10;

int n;
string str;

LL f[26];
LL g[26];

// int dp[N]; // dp[i] 表示 以i位置元素为结尾的所有子序列中有多少个 abb
LL dp;

int main() {
    cin >> n >> str;

    for (int i = 0; i < n ; i++) {
        int index = str[i] - 'a';
        dp += f[index];
        f[index] = f[index] + i - g[index];
        g[index] = g[index] + 1;
    }
    cout << dp << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")
