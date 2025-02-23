/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        // 暴力算法会超时，不写了
        sort(nums.begin(), nums.end());
        int cnt = 0, n = nums.size(); // 计数
        // for (int i = 2; i < n; i++)
        for (int i = n - 1; i >= 2; i--)
        {
            int left = 0, right = i - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i])
                {
                    cnt += right - left;
                    cout << "cnt:" << cnt << endl;
                    right--;
                }
                else
                    left++;
                cout << "left:" << left << "right" << endl;
            }
        }
        return cnt; // 调试信息会占用复杂度~
    }
};
// @lc code=end
