#include <functional>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 本题和主持人那一道题 思想是不一样的 请注意看题！！！！！
typedef long long LL;
typedef pair<LL, LL> PII;

const int N = 2e5 + 10;

int n;
vector<PII> nums(N);

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i].first >> nums[i].second;

    sort(nums.begin(), nums.begin() + n); // 左端点排序

    LL ans = 1; // 最多可以选的活动数 开始就先选了一个
    LL r = nums[0].second; // 最小右区间

    for (int i = 1; i < n ; i++) {
        if (r > nums[i].first) {
            r = min(r, nums[i].second);
        } else {
            ans++;
            r = nums[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")