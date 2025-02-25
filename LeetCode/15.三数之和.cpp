/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n;)
        {
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == -nums[i])
                {
                    ans.push_back({nums[left], nums[right], nums[i]});
                        right--,
                        left++;
                    while (left < right && nums[right + 1] == nums[right])
                        right--;
                    while (left < right && nums[left - 1] == nums[left])
                        left++;
                }
                else if (sum > -nums[i])
                    right--;
                else
                    left++;
            }
            i++;
            while (i < n && nums[i - 1] == nums[i])
                i++;
        }
        return ans;
    }
};
// @lc code=end
