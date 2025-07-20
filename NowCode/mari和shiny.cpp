#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

// ll s[300005];
// ll h[300005];
// ll y[300005];

// int main()
// {
//     ll n;
//     string str;
//     cin >> n >> str;
//     s[0] = str[0] == 's' ? 1 : 0;
//     for(ll i = 1; i < n; i++)
//     {
//         if(str[i] == 's') s[i] = s[i - 1] + 1;
//         else s[i] = s[i - 1];
//         if(str[i] == 'h') h[i] = h[i - 1] + s[i - 1];
//         else h[i] = h[i - 1];
//         if(str[i] == 'y') y[i] = y[i - 1] + h[i - 1];
//         else y[i] = y[i - 1];
//     }
//     cout << y[n - 1];
//     return 0;
// }

// 空间优化版
int main()
{
    ll n;
    string str;
    cin >> n >> str;
    ll s,h = 0,y = 0;
    if(str[0] == 's') s = 1;
    else s = 0;
    for(ll i = 1; i < n; i++)
    {
        if(str[i] == 's') s++;
        if(str[i] == 'h') h += s;
        if(str[i] == 'y') y += h;
    }
    cout << y;
    return 0;
}

// link : https://ac.nowcoder.com/acm/problem/26226