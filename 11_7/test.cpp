#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(3));

        dp[0][0] = -p[0];

        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][1] - p[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + p[i];
        }

        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};