/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        // 二维前缀和
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // 空出来一个多的行列
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 1; i < m + 1; i++)
            for (int j = 1; j < n + 1; j++) // 初始化dp数组
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
        // for (int i = 1; i < m + 1; i++)
        // {
        //     for (int j = 1; j < n + 1; j++)
        //     {
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                int x1 = max(i - k, 0) + 1, y1 = max(j - k, 0) + 1; // dp是从1开始 ans是从0开始所以要加一
                int x2 = min(i + k, m - 1) + 1, y2 = min(j + k, n - 1) + 1;
                ans[i][j] = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
            }
        return ans;
    }
};
// @lc code=end
