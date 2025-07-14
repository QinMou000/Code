// 优化解法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<ll> arr(6);
        for (auto &e : arr)
            cin >> e;
        sort(arr.begin(), arr.end());
        if ((arr[0] + arr[1] > arr[2] && arr[3] + arr[4] > arr[5]) ||
            (arr[0] + arr[2] > arr[3] && arr[1] + arr[4] > arr[5]) ||
            (arr[0] + arr[3] > arr[4] && arr[1] + arr[2] > arr[5]) ||
            (arr[0] + arr[4] > arr[5] && arr[1] + arr[2] > arr[3]))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
// 64 位输出请用 printf("%lld")

// 暴力解法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<ll> arr(6);
        for (auto &e : arr)
            cin >> e;
        sort(arr.begin(), arr.end());
        bool ans = false;
        for (int i = 0; i < 6; i++)
        {
            for (int j = i + 1; j < 6; j++)
            {
                for (int k = j + 1; k < 6; k++)
                {
                    if (arr[i] + arr[j] > arr[k])
                    {
                        vector<ll> res; // 初始化为空vector
                        for (int m = 0; m < 6; ++m)
                        {
                            if (m != i && m != j && m != k)
                            { // 使用索引比较而非值比较
                                res.push_back(arr[m]);
                            }
                        }
                        if (res[0] + res[1] > res[2])
                        {
                            ans = true;
                            goto check;
                        }
                    }
                }
            }
        }
    check:
        cout << (ans ? "Yes" : "No") << endl;
    }
}
// 64 位输出请用 printf("%lld")
// link : https://ac.nowcoder.com/acm/contest/11163/A