/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */

// @lc code=start
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int ans = 0;
        for (int i = 1; i < timeSeries.size(); i++)
        {
            int tmp = timeSeries[i] - timeSeries[i - 1]; // 算出两次攻击时间的间隔
            ans += tmp >= duration ? duration : tmp;     // 如果间隔大于dur
                                                         // ... 如果间隔小于dur...
        }
        return ans + duration; // 还有最后一次的攻击没有算进去
    }
};
// @lc code=end
