/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution
{
public:
    int GetRandom(vector<int> &nums, int l_, int r_) // 随机从vector中获得一个数
    {
        int random = rand();
        return nums[(random % r_ - l_ + 1) + l_];
    }
    void QuickSort(vector<int> &nums, int l_, int r_)
    {
        if (l_ >= r_)
            return;
        int k = GetRandom(nums, l_, r_);
        int i = l_, l = l_ - 1, r = r_ + 1;

        while (i < r)
        {
            if (nums[i] < k)
                swap(nums[++l], nums[i++]);
            else if (nums[i] == k) // 三路划分
                i++;
            else if (nums[i] > k)
                swap(nums[i], nums[--r]);
        }
        QuickSort(nums, l_, l); // 处理左右区间
        QuickSort(nums, r, r_);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        srand(time(NULL));
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// @lc code=end
