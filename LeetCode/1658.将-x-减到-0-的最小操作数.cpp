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
        for (auto e : nums) // 求和
            sum += e;
        int tar = sum - x; // 将问题转化为，求数组中和为tar的最大子数组
        if (tar < 0)       // 如果tar小于零说明就算移除全部数字都不可能满足要求：x减到零
            return -1;
        int ans = -1, n = nums.size(); // 若始终找不到能使x减到0的序列，那么最终ans就会保持为-1
        for (int left = 0, right = 0, sum = 0; right < n; right++)
        {
            sum += nums[right]; // 入窗口
            while (sum > tar)   // 判断是否出窗口
                sum -= nums[left++];
            if (sum == tar) // 找到目标子序列，记录下来
                ans = max(ans, right - left + 1);
        }
        if (ans == -1)
            return ans;
        else
            return n - ans;
    }
};
// @lc code=end
