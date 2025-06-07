/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

// @lc code=start
class Solution
{
public:
    int getSum(int a, int b)
    {
        // return a + b;
        // 2.异或运算 无进位相加
        int x = a, y = b;
        int carry = 0, xornum = 0;
        do
        {
            xornum = (x ^ y);     // 异或
            carry = (x & y) << 1; // 算进位
            x = xornum;           // 又将进位数和异或出来的无进位数相加
            y = carry;            // 循环这个过程
        } while (carry);
        return x;
    }
};
// @lc code=end
