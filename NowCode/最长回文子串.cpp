#include <algorithm>
class Solution {
  public:
    int getLongestPalindrome(string A) {
        // write code here
        // int ans = 0; // 暴力
        // for (int i = 0; i < A.size(); i++) {
        //     for (int j = 0; j <= A.size() - i; j++) {
        //         string str1 = A.substr(i, j);
        //         string str2  = str1;
        //         reverse(str1.begin(), str1.end());
        //         if (str1 == str2) {
        //             int len = str1.size();
        //             ans = max(ans, len);
        //         }
        //     }
        // }
        // return ans;
        int n = A.size();
        int ans = 0;
        for (int i = 0; i < n ; i++) { // 中心扩展算法
            int l = i - 1, r = i + 1;

            while (l >= 0 && r < n && A[l] == A[r]) {
                l--;
                r++;
            }
            ans = max(ans, r - l - 1);

            l = i, r = i + 1;
            while (l >= 0 && r < n && A[l] == A[r]) { // 考虑回文串的奇偶性
                l--;
                r++;
            }
            ans = max(ans, r - l - 1);
        }
        return ans;

        // 动态规划
        // 马拉车算法
    }
};
// link : https://www.nowcoder.com/practice/12e081cd10ee4794a2bd70c7d68f5507