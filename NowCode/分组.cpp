#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 100010;

int n,m;

int cnt[N] = { 0 };

bool check(int x) // 判断最多人数为 x 时能否分为 m 组
{
    int g = 0; // 每一次遍历算出来的所需要的组数
    for(int i = 0; i < N; i++)
        if(cnt[i] != 0) // 如果当前音部人数不为0 
            g += cnt[i] / x + (cnt[i] % x == 0 ? 0 : 1); // 计算出最多用x人一组分出来的组数
    return g <= m;
}

int main()
{
    cin >> n >> m;
    int hmax = 1;
    
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a; // 不需要数组 直接放进hash里面
        if(hmax < ++cnt[a])// 分类记录 并更新hash_max
            hmax = cnt[a];
    }
    int ans = -1; // 表示最终结果
    int kinds = 0;
    for(int i = 0; i < N; i++)
        if(cnt[i] != 0) kinds++; // 计算出音部种类
    
    if(kinds > m) cout << ans; // 边界情况直接判断
    else
    {
//         int x = 1; // 从1开始枚举每组最多分到的人数
//         while(x <= hmax) // 暴力解法
//         {
//             if(check(x))
//             {
//                 ans = x;
//                 break;
//             }
//             x++;
//         }
//         cout << ans << endl;
        
        int l = 1, r = hmax; // 二分解法
        while(l < r) 
        {
            int mid = (l + r) / 2;
            if(check(mid))
                r = mid;
            else l = mid + 1;
        }
        cout << r << endl;
    }
    return 0;
}


// link : https://ac.nowcoder.com/acm/problem/229023