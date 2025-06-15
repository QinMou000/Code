/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int d = 2 * numRows - 2;
        int n = s.size();
        string ans;
        for (int i = 0; i < n; i += d) // 处理第一行
            ans += s[i];
        for (int k = 1; k < numRows - 1; k++)
            for (int i = k, j = d - k; i < n || j < n; i += d, j += d) // 处理中间
            {
                if (i < n)
                    ans += s[i];
                if (j < n)
                    ans += s[j];
            }
        for (int i = numRows - 1; i < n; i += d) // 处理最后一行
            ans += s[i];
        return ans;
    }
};
// @lc code=end
