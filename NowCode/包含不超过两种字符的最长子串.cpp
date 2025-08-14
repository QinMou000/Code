#include <iostream>
#include <string>
#include <map>
using namespace std;

string str;
int count[26] = { 0 };

int main() {
    // 滑动窗口 + hash
    cin >> str;
    int n = str.size();
    int ans = 0;
    int cnt = 0; // 统计字符种类
    for (int left = 0, right = 0; right < n; right++) {
        // 进窗口
        if (count[str[right] - 'a']++ == 0) cnt++; // 更新哈希表 和 cnt
        // 判断
        while (cnt > 2) {
            if (--count[str[left++] - 'a'] == 0) cnt--;// 出窗口
        }
        // 更新结果
        ans = max(ans, right - left + 1);
    }
    cout << ans << endl;
    return 0;
}