#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

int n;
ll arr[N] = {0};

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    int pos = 0;
    while (pos < n) {
        if (pos == n - 1) {
            ans++;
            break;
        }
        if (arr[pos + 1] > arr[pos]) {
            while (pos + 1 < n && arr[pos + 1] >= arr[pos]) pos++;
            ans++;
        } else if (arr[pos + 1] < arr[pos]) {
            while (pos + 1 < n && arr[pos + 1] <= arr[pos]) pos++;
            ans++;
        } else while (arr[pos] == arr[pos + 1]) pos++;
        pos++;
    }
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")