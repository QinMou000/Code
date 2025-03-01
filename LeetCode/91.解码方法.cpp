/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution
{
public:
    bool single(char a)
    {
        return (a - '0') > 0 && (a - '0') <= 9;
    }
    bool both(char a, char b)
    {
        int t = (a - '0') * 10 + b - '0';
        return t >= 10 && t <= 26;
    }
    int numDecodings(string s)
    {
        int n = s.size();
        // 我们的状态表示为：dp[i]为字符串区间[0,i]上的解码方法数
        vector<int> dp(n, 0);
        // 1.初始化
        if (single(s[0]))
            dp[0] = 1; // 第一个位置可以单独编码
        if (n == 1)
            return dp[0]; // 处理边界
        if (single(s[1]))
            dp[1] += dp[0]; // 第二个位置可以单独编码
        if (both(s[0], s[1]))
            dp[1] += 1; // 第一个第二个合起来可以编码

        // 从0到第i位的解码方法应该是从0到i-1位的方法加上第i位是否能单独解码方法数
        // 第二种情况是第i位和第i-1位一起解码加上i-2的解码方法数
        for (int i = 2; i < n; i++)
        {
            if (single(s[i]))
                dp[i] += dp[i - 1];
            // 第i个可以单独编码，那么从0到i的方法有dp[i-1]种
            if (both(s[i - 1], s[i]))
                dp[i] += dp[i - 2];
            // 第i-1和第i位合起来可以编码，那么从0到i的方法再加上dp[i-2]种
        } // 如果两个都不满足，那么就没有解码方法
        return dp[n - 1];
    }
};
// @lc code=end
