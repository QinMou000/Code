/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        // 1. hash 时间On 空间On
        // 2. 高斯求和 ((首相 + 末项) * 项数 / 2) - sum(nums) 时间On 空间O1
        // 3. 异或位运算 时间On 空间O1
        int xornum = 0; 
        for (auto n : nums) // 直接将数组中的数和下标都异或起来即可
            xornum ^= n;
        for (int i = 0; i <= nums.size(); i++)
            xornum ^= i;
        return xornum;
    }
};
// @lc code=end
