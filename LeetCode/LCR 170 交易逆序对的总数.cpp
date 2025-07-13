class Solution {
    public:
        int tmp[50001]; // 全局辅助数组
        int reversePairs(vector<int>& record) {
            return MergeSort(record, 0, record.size() - 1);
        }
        int MergeSort(vector<int> &nums, int left, int right) { // 加引用老铁！！！
            // 处理边界情况
            if (left >= right)
                return 0; // 范围里没有数或者只有一个数 没有逆序对
            // 找中点
            int mid = (left + right) >> 1;
            // [left , mid] [mid + 1 , right]
    
            // 左右找分别找逆序对 + 排序
            int ans = 0;
            ans += MergeSort(nums, left, mid);
            ans += MergeSort(nums, mid + 1, right);
    
            // 排序 + 左右分别选一个数 组成逆序对
            int cur1 = left, cur2 = mid + 1, i = 0;
            while (cur1 <= mid && cur2 <= right) {
                // 选一个数 从另一边找比这个数大的数
                if (nums[cur1] > nums[cur2]) { // cur2 选定 去找另一边比 cur2 大的数
                    ans += mid - cur1 + 1;     // 这一半的数都是满足要求的
                    tmp[i++] = nums[cur2++];
                } else if (nums[cur1] <= nums[cur2])
                    tmp[i++] = nums[cur1++];
            }
            // 处理剩下的数
            while (cur1 <= mid)
                tmp[i++] = nums[cur1++];
            while (cur2 <= right)
                tmp[i++] = nums[cur2++];
            // 恢复原数组
            for (int j = left; j <= right; j++)
                nums[j] = tmp[j - left]; // tmp 每一次都是从 0 开始的
            // 返回本层的答案
            return ans;
        }
    };
    // link : https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/