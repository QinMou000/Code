#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll N = 2e5 + 10;

ll n, k;
ll nums[N] = { 0 };

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    ll max = 0, min = LLONG_MAX;
    int ans = 0;
    for (int left = 0, right = 0; right < n; right++) {
        // 入窗口
        if (nums[right] > max) max = nums[right];
        if (nums[right] < min) min = nums[right];
        // 判断
        while (max - min > k) {
            // 出窗口
            min = nums[++left];
        }
        // 更新结果
        ans = ans > right - left + 1 ? ans : right - left + 1;
    }
    cout << ans << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")