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

// link : https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false%E4%BD%9C%E8%80%85%EF%BC%9Aoffergogo%E9%93%BE%E6%8E%A5%EF%BC%9Ahttps://www.nowcoder.com/discuss/353147314330083328?sourceSSR=search%E6%9D%A5%E6%BA%90%EF%BC%9A%E7%89%9B%E5%AE%A2%E7%BD%91