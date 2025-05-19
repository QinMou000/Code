/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash; // 统计前缀和出现的次数
        hash[0] = 1;                  // 前缀和为零的次数只能为一
        int sum = 0, ret = 0;
        for (auto &e : nums)
        {
            sum += e; // 计算当前位置的前缀和
            if (hash.count(sum - k)) // 寻找在当前位置之前有多少个前缀和为sum - k
                ret += hash[sum - k];
            hash[sum]++; // 将前缀和为sum的次数++
        }
        return ret;
    }
};
// @lc code=end
