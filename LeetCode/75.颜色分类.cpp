/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, l = -1, r = nums.size();
        while (i < r)
        {
            if (nums[i] == 0)
                swap(nums[++l], nums[i++]);
            else if (nums[i] == 1)
                i++;
            else if (nums[i] == 2)
                swap(nums[i], nums[--r]);
        }
    }
};
// @lc code=end
