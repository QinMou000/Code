/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    int fun(int n)
    {
        int t;
        int ans = 0;
        while (n)
        {
            t = n % 10;
            cout << "t:" << t << endl;
            ans += t * t;
            n /= 10;
            cout << "ans:" << ans << endl;
        }
        return ans;
    }
    bool isHappy(int n)
    {
        set<int> s;
        int ans = n;
        while (1)
        {
            ans = fun(ans);
            cout << "################" << endl;
            cout << "ans:" << ans << endl;
            if (s.find(ans) != s.end())
                return false;
            if (ans == 1)
                return true;
            s.insert(ans);
        }
    }
};
// @lc code=end
