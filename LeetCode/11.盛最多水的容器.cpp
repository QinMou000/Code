/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // int max = 0;
        // for (int i = 0; i < height.size(); i++)
        //     for (int j = i + 1; j < height.size(); j++)
        //     {
        //         int ans = (j - i) * min(height[i],height[j]);
        //         if(ans > max) max = ans;
        //     }
        // return max; 暴力算法，超时了

        int n = height.size();
        int left = 0, right = n - 1,ans = 0; // 对撞指针
        while (left < right)
        {
            ans = max(ans, min(height[left], height[right]) * (right - left));
            if(height[left] > height[right]) right--;
            else left++;
        }
        return ans;
    }
};
// @lc code=end
