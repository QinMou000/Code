#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int m, n;

int main() {
    cin >> m >> n;
    vector<vector<ll>> arr(m + 1, vector<ll>(n + 1)); // 第一行第一列存储每一行每一列的和
    vector<vector<ll>> ans(m, vector<ll>(n));

    for (int i = 1; i < m + 1; i++)
        for (int j = 1; j < n + 1; j++) {
            scanf("%lld", &arr[i][j]);
            arr[i][0] += arr[i][j]; // 将数字都累加到第一行与第一列
            arr[0][j] += arr[i][j];
        }
    // 注意 arr 与 ans 之间的对应关系
    for (int i = 0; i < m ; i++)
        for (int j = 0; j < n ; j++)
            ans[i][j] = arr[0][j + 1] + arr[i + 1][0] - arr[i + 1][j + 1]; // 多加了一个 减去即可
    for (int i = 0; i < m ; i++)
    {
        for (int j = 0; j < n ; j++)    
            printf("%lld ", ans[i][j]); // 输出答案
        printf("\n");
    }
    return 0;
}

// 64 位输出请用 printf("%lld")

// link : https://ac.nowcoder.com/acm/contest/5600/I