/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 */

// @lc code=start
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        // (a - b) % p = 0 <=> a % p = b % p 同余定理
        // C++ Java中负数模上正数的修正 （a为负数） a % b => (a % b + b) % b
        // 只需找在[0 , i - 1]区间内有多少个前缀和的余数为(sum % k + k) % k
        unodered_map<int, int> hash; // 记录前缀和的余数
        hash[0] = 1;                 // 排除前面的全部前缀和就为k，此时的余数为1，但也算一个
        int ret = 0, sum = 0;
        for (auto &e : nums)
        {
            sum += e;
            if (hash.count((sum % k + k) % k))
                ret += hash[(sum % k + k) % k];
            hash[(sum % k + k) % k]++;
        }
        return ret;
        // 本题的一些细节可以参考和为k的子数组
    }
};
// @lc code=end
