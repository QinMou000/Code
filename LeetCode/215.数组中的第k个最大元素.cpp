/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution
{
public:
    int GetRandom(vector<int> &num, int l, int r)
    {
        return num[rand() % (r - l + 1) + l];
    }

    int quicksort(vector<int> &num, int l, int r, int k)
    {
        if (r == l)
            return num[r];
        // 随机选择基准元素
        int key = GetRandom(num, l, r);
        // 数组分三块
        int left = l - 1;
        int right = r + 1;
        int i = l;
        while (i < right)
        {
            if (num[i] > key)
                swap(num[--right], num[i]); // 和right-1交换
            else if (num[i] < key)
                swap(num[++left], num[i++]); // 和left+1交换
            else
                i++; // 就放在中间 不用交换
        }
        int c = r - right + 1;    // 看图！！！
        int b = right - left - 1; // 分情况只在一个区间去找
        if (c >= k)
            return quicksort(num, right, r, k);
        else if (b + c >= k)
            return key;
        else
            return quicksort(num, l, left, k - b - c);
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        srand(time(nullptr));
        return quicksort(nums, 0, nums.size() - 1, k);
    }
};
// @lc code=end
