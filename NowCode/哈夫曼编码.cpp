#include <functional>
#include <iostream>
#include <queue>
using namespace std;

typedef long long LL;

priority_queue<LL, vector<LL>, greater<LL>> heap; // 小根堆
int n;

int main() {
    cin >> n;
    while (n --) {
        LL x;
        cin >> x;
        heap.push(x);
    }
    LL ans = 0;
    while (heap.size() > 1) {
        LL sum = 0;
        ans += heap.top();
        sum += heap.top();
        heap.pop();
        ans += heap.top();
        sum += heap.top();
        heap.pop();
        heap.push(sum);
    }
    cout << ans << endl;
    return 0;
}
