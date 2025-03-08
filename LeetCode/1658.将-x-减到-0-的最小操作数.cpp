/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int sum = 0;
        for (auto e : nums)
            sum += e;
        int tar = sum - x;
        if (tar < 0) return -1;
        sum = 0;
        for(int left = 0, right = 0;right < nums.size();right++)
        {
            sum += nums[right];
            
        }

    }
};
// @lc code=end
