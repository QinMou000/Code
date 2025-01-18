#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

double myPow(double x, int n)//递归
{
    if (n == 0 || x == 1) {
        return 1;
    }
    if (n < 0) {
        return 1 / (x * myPow(x, -(n + 1)));
    }
    if (n % 2 == 0) {
        return myPow(x * x, n / 2);
    }
    else {
        return x * myPow(x * x, (n - 1) / 2);
    }
}

double myPow(double x, int n)//常法
{
    int i = n;
    double y = 1;
    if (n == 0 || x == 1)
        return 1;
    while (n != 0)
    {
        if (n == 1 || n == -1)
            break;
        if (n % 2 != 0)
            y = x * y;
        x = x * x;
        n /= 2;
    }
    return i < 0 ? 1 / (x * y) : x * y;
}

#if 0
long double myPow(long double x, long n)
{
    double ret = 1;
    if (n > 0)
    {
        if (n >= 1)
        {
            for (int i = 0; i < n; i++)
            {
                ret *= x;
            }
        }
        else
        {
            ret = x;
        }
    }
    else if (n < 0)
    {
        if (n < -1)
        {
            for (int i = 0; i > n; i--)
            {
                ret *= 1 / x;
            }
        }
        else
        {
            ret = 1 / x;
        }
    }
    return ret;
}

int main()
{
    myPow(2.1,3);
}

double myPow(double x, int n)//实现pow(x, n),即计算x的整数n次幂函数。
{
    if (n > 0)
    {
        if (n > 1)
            return x * myPow(x, n - 1);
        else
            return x;
    }
    else if (n < 0)
    {
        if (n < -1)
            return 1 / x * myPow(x, n + 1);
        else
            return 1 / x;
    }
    else
        return 1;
}

/*给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
如果反转后整数超过 32 位的有符号整数的范围[−231, 231 − 1] ，就返回 0。
假设环境不允许存储 64 位整数（有符号或无符号）.
*/
int reverse(int x) 
{
	long long tmp = 0;
	while (x)
	{
		tmp = tmp * 10 + x % 10;
		x /= 10;
	}
	if (tmp < -pow(2, 31) || tmp >= pow(2, 31))
		return 0;
	else
		return tmp;
}

int main()
{
		
	return 0;
}
#endif