/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> hash; // <前缀和, 下标>
        hash[0] = -1;                 // 默认有一个前缀和的下标为-1
        int sum = 0, ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i] == 0 ? -1 : 1;      // 将当前位置的前缀和加上
            if (hash.count(sum))               // 如果这个hash里面有相同的前缀和，
                ret = max(ret, i - hash[sum]); // 将当前的下标和hash里面的前一个前缀和为sum的下标做计算与ret比较最大值得结果
            else
                hash[sum] = i; // 将计算后的前缀和连同下标一起放进hash里面
        }
        return ret;
    }
};
// @lc code=end
