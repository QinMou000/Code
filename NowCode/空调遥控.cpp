// 排序 + 滑动窗口 or 排序+二分
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10;

int n,p;
int arr[N] = {0};

int main()
{
    cin >> n >> p;
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    
    sort(arr, arr + n);
    int max = 0, min = N, ans;
    for(int left = 0,right = 0; right < n;right++)
    {
        // 进窗口
        // 判断
        if(arr[right] - arr[left] <= 2 * p)
            ans = right - left + 1;// 更新结果
        else
            left++;// 出窗口
    }
    
    cout << ans << endl;
    return 0;
}

// link : https://ac.nowcoder.com/acm/problem/229310