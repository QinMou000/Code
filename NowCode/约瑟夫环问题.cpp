class Solution {
    public:
      /**
       * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
       *
       *
       * @param n int整型
       * @param m int整型
       * @return int整型
       */
      int LastRemaining_Solution(int n, int m) {
          // write code here
          int p = 0;
          for (int i = 2; i <= n; i++) {
              p = (p + m) % i;
          }
          return p;
      }
  };
// Link : https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&tqId=11199