#include <asm-generic/errno.h>
#include <climits>
#include <iostream>
using namespace std;

const int N = 1005;

int dp[N][N] = {0}; // 在区间 [i, j] 范围内最长的回文子串的长度

int main()
{
    // 区间 dp 问题
    string s;
    cin >> s;
    int n = s.size();
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;
}

// link : https://www.nowcoder.com/practice/82297b13eebe4a0981dbfa53dfb181fa?tpId=382&tqId=44662&rp=1&sourceUrl=%2Fexam%2Foj&difficulty=undefined&judgeStatus=undefined&tags=&title=%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E5%BA%8F%E5%88%97

// 下面是我又没看清题目 写出来的史

// #include <climits>
// #include <iostream>
// using namespace std;

// int main() {
//     // 中心扩展算法
//     string s;
//     cin >> s;
//     int n = s.size();
//     int left, right, ans = INT_MIN;
//     for (int i = 0; i < n; i++) {
//         // 以 i 为中心
//         left = i - 1, right = i + 1;
//         while (left >= 0 && right <= n - 1 && s[left] == s[right]) {
//             left--;
//             right++;
//         }
//         ans = max(ans, right - left + 1);

//         // 以 i 和 i+1 为中心
//         left = i, right = i + 1;
//         while (left >= 0 && right <= n - 1 && s[left] == s[right]) {
//             left--;
//             right++;
//         }
//         ans = max(ans, right - left + 1);
//     }
//     cout << ans << endl;
// }
