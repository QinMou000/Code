/*
 * @lc app=leetcode.cn id=1576 lang=cpp
 *
 * [1576] 替换所有的问号
 */

// @lc code=start
class Solution
{
public:
    void FindAndSet(string &s, int i)
    {
        for (int j = 0; j < 26; j++)
            if (i == 0)
            {
                if ('a' + j != s[i + 1]) // 处理边界情况
                    s[i] = 'a' + j;
            }
            else if (i == s.size() - 1)
            {
                if ('a' + j != s[i - 1]) // 处理边界情况
                    s[i] = 'a' + j;
            }
            else if ('a' + j != s[i - 1] && 'a' + j != s[i + 1])
                s[i] = 'a' + j;
    }

    string modifyString(string s)
    {
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '?')
                FindAndSet(s, i);
        return s;
    }
};

// @lc code=end
