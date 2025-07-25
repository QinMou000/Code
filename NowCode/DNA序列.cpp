#include <iostream>
using namespace std;

int main() {
    string str;
    int n;
    cin >> str >> n;
    string ans;
    int cnt = 0; // 记录 CG 的个数
    int MaxCnt = 0; // 标记最大 CG 个数
    int l = 0, r = 0;

    while (r < str.size()) {
        if (str[r] == 'G' || str[r] == 'C') cnt++; // 进窗口
        if (r - l + 1 > n) { // 判断什么时候出窗口
            if (str[l] == 'G' || str[l] == 'C') cnt--;
            l++;
        }
        if (cnt > MaxCnt) { // 更新结果
            ans = str.substr(l, n);
            cnt = MaxCnt;
        }
        r++;
    }
    cout << ans << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")

// link : https://www.nowcoder.com/practice/e8480ed7501640709354db1cc4ffd42a?tpId=382&tqId=43564&rp=1&sourceUrl=%2Fexam%2Foj&difficulty=undefined&judgeStatus=undefined&tags=&title=DNA