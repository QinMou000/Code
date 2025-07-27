// #include <climits>
// #include <iostream>
// using namespace std;

// typedef long long ll;

// const int N = 2e5 + 10;

// int n, k;

// //分别表示蜜柑的甜度和酸度
// ll a[N];
// ll b[N];

// // 滑动窗口
// int main() {
//     // 输入数据
//     cin >> n >> k;
//     for (int i = 0; i < n; i++)
//         cin >> b[i];
//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     ll a_sum = 0; // 总甜度
//     ll b_sum = 0; // 总酸度

//     ll a_max = 0; // 最大甜度
//     ll b_min = INT_MAX; // 最小酸度
//     for (int l = 0, r = 0; r < n; r++) {
//         // 入窗口
//         a_sum += a[r];
//         b_sum += b[r];
//         // 判断 if while 都可 固定窗口
//         while (r - l + 1 > k) {
//             // 出窗口
//             a_sum -= a[l];
//             b_sum -= b[l];
//             l++;
//         }
//         // 更新结果
//         if (r - l + 1 == k) {
//             if (a_sum > a_max || (a_sum == a_max && b_sum < b_min)) {
//                 a_max = a_sum;
//                 b_min = b_sum;
//             }
//         }
//     }
//     cout << a_max << " " << b_min << endl;
//     return 0;
// }
// 没看清题目写的代码 呜呜呜~~~



#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, k;
template<class T>
class Com { // 仿函数 控制排序
  public:
    bool operator()(const pair<T, T>& a, const pair<T, T>& b) {
        if (a.first > b.first || (a.first == b.first && a.second < b.second))
            return true;
        else return false;
    }
};

int main() {
    // 输入数据
    cin >> n >> k;
    vector<pair<ll, ll>> arr(n + 10);
    for (int i = 0; i < n; i++)
        cin >> arr[i].second; // 输入酸度
    for (int i = 0; i < n; i++)
        cin >> arr[i].first; // 输入甜度

    sort(arr.begin(), arr.end(), Com<ll>());

    ll a_sum = 0; // 总甜度
    ll b_sum = 0; // 总酸度
    int i = 0;
    while (k--) { // 取前 k 个蜜柑
        a_sum += arr[i].first;
        b_sum += arr[i].second;
        i++;
    }
    cout << b_sum << " " << a_sum << endl;
    return 0;
}

// link : https://www.nowcoder.com/practice/c43a0d72d29941c1b65c857d8ac9047e