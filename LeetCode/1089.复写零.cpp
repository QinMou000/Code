/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

// @lc code=start
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        // 从后往前复写
        int cur = 0, dest = -1, n = arr.size();
        // 1.基于异地复写的本地复写模拟
        while (cur < n)
        {
            if (arr[cur])
                dest++;
            else
                dest += 2;
            if (dest >= n - 1)
                break; // 注意判断条件
            cur++;
        }
        // 2.解决边界问题
        if (dest >= n)
        {
            arr[n - 1] = 0;
            dest -= 2;
            cur--;
        }
        // 3.从后往前复写
        while (cur >= 0)
        {
            if (arr[cur])
                arr[dest--] = arr[cur--];
            else
            {
                arr[dest--] = 0;
                arr[dest--] = 0;
                cur--;
            }
        }
    }
};
// @lc code=end
