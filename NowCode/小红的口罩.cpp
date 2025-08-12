#include <functional>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5 + 10;
int n, k;
priority_queue<int, vector<int>, greater<int>> heap; // 小根堆

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        heap.push(tmp);
    }
    int ans = 0; // 天数
    int x = 0; // 累计不舒适度
    while (true) {
        int min =  heap.top(); // 每次取最小的不舒适度出来
        heap.pop();
        x += min;
        if (x > k)
            break;
        ans++;
        heap.push(min * 2);
    }
    // 别被题目误导了
    cout << ans << endl;
}
// 64 位输出请用 printf("%lld")