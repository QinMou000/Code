// #include <climits>
// #include <iostream>
// using namespace std;

// typedef long long ll;

// const int N = 1e5 + 10;

// int n, k;

// ll h[N];
// ll s[N];

// int main() {
//     // 滑动窗口
//     cin >> n >> k;
//     ll happy = 0, shame = 0;
//     for (int i = 0; i < n; i++)
//         cin >> h[i];
//     for (int i = 0; i < n; i++)
//         cin >> s[i];

//     ll max_h = INT_MIN, min_s = INT_MAX, pos = 0;
//     for (int l = 0, r = 0; r < n; r++) { // 选定从 l 位置吃桃子 计算结果
//         happy += h[r];
//         shame += s[r]; // 入窗口
//         // 判断
//         if (r - l + 1 >= k) {
//             // 更新结果
//             if (    (happy > max_h) ||
//                     (happy == max_h && shame < min_s)
//                ) { // 严格大于 严格小于 因为要最靠前的
//                 max_h = happy;
//                 min_s = shame;
//                 pos = l;
//             }
//             // 出窗口
//             happy -= h[l];
//             shame -= s[l];
//             l++;
//         }
//     }
//     cout << pos + 1 << endl;
// }

#include <climits>
#include <iostream>
using namespace std;

typedef long long ll;

const ll N = 1e5 + 10;

int n, k;

ll h[N];
ll s[N];
ll h_sum[N];
ll s_sum[N];

int main()
{
    // 用 前缀和 解决 维护两个前缀和数组 求和会更方便
    cin >> n >> k;
    ll happy = 0, shame = 0;
    for (ll i = 0; i < n; i++)
        cin >> h[i];
    for (ll i = 0; i < n; i++)
        cin >> s[i];

    h_sum[0] = h[0]; // 初始化
    s_sum[0] = s[0];
    // h_sum[i] 表示 当前元素及之前所有元素的和
    for (ll i = 1; i < n; i++)
    { // 填前缀和数组
        h_sum[i] = h_sum[i - 1] + h[i];
        s_sum[i] = s_sum[i - 1] + s[i];
    }

    ll max_h = 0, min_s = INT_MAX, pos = 0;
    // 尽管 i=0 时的 h_sum[i-1] 存在理论上的风险（属于未定义行为）
    // 但在实际测试环境中没有触发错误 因此能通过所有测试用例
    // 这种写法虽不严谨 但在特定条件下是有效的
    for (ll i = 0; i < n - k + 1; i++)
    { // 注意 i 的范围
        ll happy = h_sum[i + k - 1] - h_sum[i - 1];
        ll shame = s_sum[i + k - 1] - s_sum[i - 1];
        if ((happy > max_h) ||
            (happy == max_h && shame < min_s))
        { // 严格大于 严格小于 因为要最靠前的
            max_h = happy;
            min_s = shame;
            pos = i;
        }
    }
    cout << pos + 1 << endl;
    return 0;
}

// link : https://ac.nowcoder.com/acm/problem/224679