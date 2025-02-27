/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = nums[0], ans = INT_MAX;
        while (right < n)
        {
            if (sum >= target)
            {
                ans = min(right - left + 1, ans);
                sum -= nums[left++];
            }
            else if (sum < target && ++right < n)
                sum += nums[right];
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};
// @lc code=end
