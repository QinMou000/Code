/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        for (int i = 0; i < 32; i++) // 一次修改ret中的每一位
        {
            int total = 0;
            for (auto n : nums)
                total += n >> i & 1; // 确认n的第i位是否为1
            if (total % 3)
                ret |= (1 << i); // 模三后的结果设置到ret对应的比特位上
        }
        return ret;
    }
};
// @lc code=end
