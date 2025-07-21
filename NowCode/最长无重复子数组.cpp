class Solution {
    public:
      typedef long long ll;
      ll hash[100005];
  
      int maxLength(vector<int>& arr) {
          // write code here
          ll n = arr.size();
          ll ans = 0;
  
          for (ll l = 0, r = 0; r < n ; r++) {
              hash[arr[r]]++;
              while (hash[arr[r]] != 1) { // 出现重复数据
                  hash[arr[l]]--; // 出窗口
                  l++;
              }
              // 更新结果
              ans = max(ans, r - l + 1);
          }
          return ans;
      }
  };

 // link : https://www.nowcoder.com/practice/b56799ebfd684fb394bd315e89324fb4