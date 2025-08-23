class Solution {
  public:
    const static int N = 2e5 + 10;
    int dp[N] = {0}; // dp[i] 表示 0 ~ i 中最小值

    int getDis(vector<int>& A, int n) {
        dp[0] = A[0];
        for (int i = 1; i < n ; i++) {
            dp[i] = min(dp[i - 1], A[i]);
        }
        int ans = 0;
        for (int i = 1; i < n ; i++) {
            ans = max(ans, A[i] - dp[i - 1]);
        }
        return ans;
    }
};