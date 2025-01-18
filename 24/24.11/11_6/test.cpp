#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& c) {
        int m = c.size();
        vector<vector<int>> dp(m, vector<int>(3));
        dp[0][0] = c[0][0];
        dp[0][1] = c[0][1];
        dp[0][2] = c[0][2];
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + c[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + c[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + c[i][2];
        }
        return min(min(dp[m - 1][0], dp[m - 1][1]), dp[m - 1][2]);
    }
};