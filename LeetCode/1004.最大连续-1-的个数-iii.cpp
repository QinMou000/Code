/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int ans = 0; // 将窗口中的0的个数维持在小于等于k个
        for (int left = 0, right = 0, zero = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0) // 进窗口，如果right位置为0加加zero
                zero++;
            while (zero > k)           // 当窗口里面的零大于k，出窗口
                if (nums[left++] == 0) // 如果出窗口的位置为零zero减减直到zero等于k时
                    zero--;
            ans = max(ans, right - left + 1); // 就是结果出现的时候
        }
        return ans;
    }
};
// @lc code=end
