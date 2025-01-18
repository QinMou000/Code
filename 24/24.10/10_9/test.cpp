#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                if (obstacleGrid[i - 1][j - 1] == 1)
                    dp[i][j] = 0;
            }
        return dp[m][n];
    }
};

int jewelleryValue(vector<vector<int>>& frame) {
    int ans = frame[0][0];
    int i = 0;
    int j = 0;
    for (int i = 1; i < frame.size(); i++)
        for (int j = 1; j < frame[0].size(); j++)
        {
            if (frame[i + 1][j] > frame[i][j + 1])
                ans += frame[i + 1][j];
            else
                ans += frame[i][j + 1];
        }
    return ans;
}
int main()
{
    vector<vector<int>> V1({ {0,0} });
    vector<vector<int>>  V2{ {1, 3, 1},{1, 5, 1}, {4, 2, 1} };     //[[1, 3, 1], [1, 5, 1], [4, 2, 1]]
    //cout << V1[0].size() << endl;
    //cout << V1.size() << endl;
    //cout << Solution().uniquePathsWithObstacles(V) << endl;
    //cout<<jewelleryValue(V2);
    int arr[] = { 1,2,3,4 };
    for (auto e : arr)cout << e << endl;

    return 0;
}