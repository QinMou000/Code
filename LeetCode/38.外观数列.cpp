/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        string ret = "1";
        for (int j = 0; j < n - 1; j++) // 循环 n - 1 次
        {
            string tmp;
            int l = 0, r = 0;
            while (r < ret.size())
            {
                while (r < ret.size() && ret[r] == ret[l])
                    ++r;
                // 解释
                tmp += to_string(r - l) + ret[l];
                l = r;
            }
            ret = tmp;
        }
        return ret;
    }
};
// @lc code=end
