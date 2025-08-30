class Solution {
  public:
    const static int N = 1e5 + 10;
    typedef long long ll;
    ll dp[N] = {0}; // dp[i] 表示长度为 i 的最小末尾
    ll pos = 0;
    int LIS(vector<int>& a) {
        for (auto x : a) {
            // 查找 x 应该放在哪个位置
            if (pos == 0 || x > dp[pos])
                dp[++pos] = x;
            else {
                // 二分优化查找 x 放的位置
                int l = 1, r = pos;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (dp[mid] >= x) r = mid;
                    else l = mid + 1;
                }
                dp[l] = x;
            }
        }
        return pos;
    }
};