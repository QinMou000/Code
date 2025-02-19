/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int dest = -1;
        int cur = 0;
        while(cur < nums.size())
        {
            if(nums[cur])
            {
                dest++;
                swap(nums[dest], nums[cur++]);
            }
            else
                cur++;
        }
    }
};
// @lc code=end

