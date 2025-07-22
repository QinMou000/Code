#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int arr[N] = {0};
int f[N] = {0}; // 表示选到当前数字时 当前数字必选 的最高分数
int g[N] = {0}; // 表示选到当前数字时 当前数字不选 的最高分数


int hash_map[10005] = {0}; // 统计每个数字出现多少次

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++) {
        hash_map[arr[i]]++; // 统计每个数字出现多少次
    }

    f[0] = 0;
    g[0] = 0;

    for (int i = 1; i < 10005; i++) { // 遍历 hash 表
        f[i] = g[i - 1] + hash_map[i] * i;
        g[i] = max(g[i - 1], f[i - 1]);
    }
    cout << max(f[10004], g[10004]);
}

// 64 位输出请用 printf("%lld")

// link : https://www.nowcoder.com/practice/ddaaf110911a453da61e8e020df86a6c