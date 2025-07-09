/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution
{
public:
    // int GetRandom(vector<int> &nums, int l_, int r_) // 随机从vector中获得一个数
    // {
    //     int random = rand();
    //     return nums[(random % r_ - l_ + 1) + l_];
    // }
    // void QuickSort(vector<int> &nums, int l_, int r_)
    // {
    //     if (l_ >= r_)
    //         return;
    //     int k = GetRandom(nums, l_, r_);
    //     int i = l_, l = l_ - 1, r = r_ + 1;

    //     while (i < r)
    //     {
    //         if (nums[i] < k)
    //             swap(nums[++l], nums[i++]);
    //         else if (nums[i] == k) // 三路划分
    //             i++;
    //         else if (nums[i] > k)
    //             swap(nums[i], nums[--r]);
    //     }
    //     QuickSort(nums, l_, l); // 处理左右区间
    //     QuickSort(nums, r, r_);
    // }
    // vector<int> sortArray(vector<int> &nums)
    // {
    //     srand(time(NULL));
    //     QuickSort(nums, 0, nums.size() - 1);
    //     return nums;
    // }

    vector<int> tmp; // 全局辅助数组
    void MergeSort(vector<int> &num, int left, int right)
    {
        if (left >= right)
            return;
        // 选中间元素 划分左右区间
        int mid = (right + left) >> 1;
        // [left, mid]  [mid + 1, right]
        MergeSort(num, left, mid);
        MergeSort(num, mid + 1, right);
        int l = left, r = right;
        // 合并两个有序数组
        // 辅助数组
        vector<int> tmp(right - left + 1);
        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid && cur2 <= right) // 可以等于
            tmp[i++] = num[cur1] < num[cur2] ? num[cur1++] : num[cur2++];
        // 可能有一个区域里面没有遍历完
        while (cur1 <= mid)
            tmp[i++] = num[cur1++];
        while (cur2 <= right)
            tmp[i++] = num[cur2++];

        // 恢复原数组
        for (int i = left; i <= right; i++)
            num[i] = tmp[i - left];
    }

    vector<int> sortArray(vector<int> &nums)
    {
        tmp.resize(nums.size()); // 预留好空间
        MergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end
