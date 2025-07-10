#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s1, s2;
    vector<string> strs(n);
    cin >> s1 >> s2;
    for (auto& e : strs)
        cin >> e;
    int prev1 = -1, prev2 = -1;// 预处理思想
    int ans = INT_MAX;
    for (int i = 0; i < strs.size(); i++) {
        if (strs[i] == s1) {
            if (prev2 != -1)
                ans = min(ans, i - prev2);
            prev1 = i;
        }
        if (strs[i] == s2) {
            if (prev1 != -1)
                ans = min(ans, i - prev1);
            prev2 = i;
        }
    }
    if (ans == INT_MAX)
        cout << -1;
    else
        cout << ans;
}
// 64 位输出请用 printf("%lld")
// https://www.notion.so/day2-22a67e785d408005bc0eed5bb809b290?source=copy_link