#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 2, vector<int>(n + 2, INT_MAX));
        dp[0][1] = 0;
        dp[1][0] = 0;
        for (int i = 1; i < m + 1; i++)
            for (int j = 1; j < n + 1; j++)
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j])
                + grid[i - 1][j - 1];
        // for(auto E : dp)
        // {
        //     for(auto e : E)
        //         cout<< e << " ";
        //     cout<<endl;
        // }
        return dp[m][n];
    }
};