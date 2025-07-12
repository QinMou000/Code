class Solution {
    public:
      string solve(string s, string t) {
          reverse(s.begin(), s.end());
          reverse(t.begin(), t.end());
          vector<int> arr(s.size() + t.size());
          for (int i = 0; i < s.size() ; i++) {
              for (int j = 0 ; j < t.size() ; j++) {
                  arr[i + j] += (s[i] - '0') * ( t[j] - '0'); // 无进位相乘
              }
          }
          // 处理进位
          int c = 0;
          string ans;
          for (auto e : arr) {
              c += e;
              ans += c % 10 + '0';
              c /= 10;
          }
          // 处理 最后的 c 不为 0 的情况
          while (c) {
              ans += c % 10 + '0';
              c /= 10;
  
          }
          // 处理末尾的0
          while (ans.size() > 1 && ans.back() == '0') {
              ans.pop_back();
          }
  
          reverse(ans.begin(), ans.end());
          return ans;
      }
  };
  // link : https://www.nowcoder.com/questionTerminal/c4c488d4d40d4c4e9824c3650f7d5571