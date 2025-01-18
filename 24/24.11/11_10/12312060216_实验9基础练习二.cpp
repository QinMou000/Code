#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

// 二分
int binarySearch(vector<int> arr, int x) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;  // 找到元素，返回其索引
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // 未找到元素，返回 -1
}

int main() {
    srand(time(nullptr));
    vector<int> v(1024);
    
    for (auto& e : v)
        e = rand()%1025; //生成小于1025的随机值

    sort(v.begin(), v.end());// 排序使之满足二段性

    int x;
    cin >> x;

    cout<<binarySearch(v, x);// 返回下标

    return 0;
}