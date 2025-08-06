#include <functional>
class Solution {
  public:
    int minmumNumberOfHost(int n, vector<vector<int> >& nums) {

        sort(nums.begin(), nums.end()); // 按左端点排序

        priority_queue<int, vector<int>, greater<int>> pq; // 小根堆
        pq.push(nums[0][1]); // 存第一个区间的右端点

        for (int i = 1 ; i < nums.size(); i++) {
            if (nums[i][0] >= pq.top()) { // 没有重叠部分
                pq.pop();
                pq.push(nums[i][1]);
            } else { // 有重叠的部分
                pq.push(nums[i][1]); // 重新安排一个主持人
            }
        }
        return pq.size();
    }
};

// link : https://www.nowcoder.com/practice/4edf6e6d01554870a12f218c94e8a299