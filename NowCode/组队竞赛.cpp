#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

unsigned long long arr[N] = {0};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n * 3; i++)
        cin >> arr[i];
    sort(arr, arr + n * 3);

    int i = n * 3 - 2; // 从倒数第二个数开始取 取n次
    unsigned long long ans = 0;
    while (n--) {
        ans += arr[i];
        // cout << ans << endl;
        i -= 2;
    }
    cout << ans << endl;

}
// 64 位输出请用 printf("%lld")

// link : 