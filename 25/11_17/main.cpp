#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int> &arr, int target);

int lower_bound(vector<int> &nums, int target);

void QuickSort(vector<int> &nums, int left, int right);

void MergeSort(vector<int> &nums, int left, int right);

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    int target1 = 8;
    int target2 = 5;
    int target3 = 0;

    int index1 = BinarySearch(arr, target1);
    int index2 = lower_bound(arr, target2);
    int index3 = lower_bound(arr, target3);

    QuickSort(arr, 0, arr.size() - 1);

    for (auto &e: arr)
        cout << e << " ";
    cout << endl;

    MergeSort(arr, 0, arr.size() - 1);

    for (auto &e: arr)
        cout << e << " ";
    cout << endl;

    return 0;
}

int patition(vector<int> &nums, int left, int right) {
    int l = left, r = right;
    while (l < r) {
        while (l < r && nums[left] >= nums[r])
            r--;
        while (l < r && nums[left] <= nums[l])
            l++;
        swap(nums[l], nums[r]);
    }
    swap(nums[left], nums[l]);
    return l;
}

void QuickSort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int pviot = patition(nums, left, right);

    QuickSort(nums, left, pviot - 1);
    QuickSort(nums, pviot + 1, right);
}

void MergeSort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int mid = left + ((right - left) >> 1);

    MergeSort(nums, left, mid); // 这个和快排是有区别的!!!
    MergeSort(nums, mid + 1, right);

    vector<int> tmp(right - left + 1); // 辅助数组
    int index = 0; // 专门给辅助数组用的下标
    int l = left, r = mid + 1; // 注意两个数组的开始下标
    while (l <= mid && r <= right) {
        if (nums[l] < nums[r])
            tmp[index++] = nums[l++];
        else
            tmp[index++] = nums[r++];
    }
    while (l <= mid)
        tmp[index++] = nums[l++];
    while (r <= right)
        tmp[index++] = nums[r++];

    // 写回原数组
    for (int i = 0; i < tmp.size(); i++)
        nums[i + left] = tmp[i];
}

int BinarySearch(vector<int> &arr, int target) {
    // 二分
    // 时间 O(nlogn)
    // 空间 O(1)
    int n = arr.size();
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
            left = mid + 1;
        else // 直接 else 没有条件 包含大于等于
            right = mid - 1;
    }
    cout << "left : " << left << " right : " << right << endl;
    return left;
}

int lower_bound(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    cout << "left : " << left << " right : " << right << endl;
    return left; // 这样求出来的是左边界
}
