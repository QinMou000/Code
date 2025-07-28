#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int t, n;

bool check(string str1, string str2) {
    int hash1[26] = {0};
    int hash2[26] = {0};
    // 统计两个字符串中有哪些字符出现
    for (int i = 0; i < str1.size(); i++)
        hash1[str1[i] - 'a']++;
    for (int i = 0; i < str2.size(); i++)
        hash2[str2[i] - 'a']++;

    for (int j = 0 ; j < 26; j++)
        if (hash1[j] > 0 && hash2[j] > 0)
            return true;
    return false;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // 输入每行的字符串
        }
        int left = 0, right = n - 1;
        bool ans = 1;
        if (left == right) {
            cout << "Yes" << endl;
            continue;
        }
        while (left < right) {
            // 检查两个字符串中是否有相同字符
            if (check(arr[left], arr[right])) {
                left++;
                right--;
            } else {
                ans = false;
                break;
            }
        }
        if (ans) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
// 64 位输出请用 printf("%lld")

// link : https://ac.nowcoder.com/acm/contest/10746/H