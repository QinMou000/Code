#include <algorithm>
class Solution {
  public:
    string solve(string s, string t) {
        int c = 0; // 进位标识
        int slen = s.size() - 1;
        int tlen = t.size() -  1;
        string ans;
        while (slen >= 0 || tlen >= 0 || c > 0) {
            if (slen >= 0)
                c += s[slen--] - '0';
            if (tlen >= 0)
                c += t[tlen--] - '0';
            ans += c % 10 + '0';
            c /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// link : https://www.nowcoder.com/questionTerminal/11ae12e8c6fe48f883cad618c2e81475