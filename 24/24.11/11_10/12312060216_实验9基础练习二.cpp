#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

// ����
int binarySearch(vector<int> arr, int x) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;  // �ҵ�Ԫ�أ�����������
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // δ�ҵ�Ԫ�أ����� -1
}

int main() {
    srand(time(nullptr));
    vector<int> v(1024);
    
    for (auto& e : v)
        e = rand()%1025; //����С��1025�����ֵ

    sort(v.begin(), v.end());// ����ʹ֮���������

    int x;
    cin >> x;

    cout<<binarySearch(v, x);// �����±�

    return 0;
}