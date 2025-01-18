#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
/*
int main(int argc, char* argv[])
{
    // 请在此输入您的代码
    int n = 0;
    scanf("%d", &n);
    int ans = 0;
    int input = 0;
    while (n--)
    {
        scanf("%d",&input);
        ans = ans * 10 + input;
    }
    ans = ans % 998244353;
    printf("%d", ans);
    return 0;
}*/

int main(int argc, char* argv[])
{
    // 请在此输入您的代码
    int x,y;
    scanf("%d%d", &x, &y);
    int ans = 0;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if ((i == i * j || j == i * j)&&j >= i)
            {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}