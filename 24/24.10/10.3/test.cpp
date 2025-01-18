#define _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<vector<int>> V;
    for (int i = 0; i < n;)
    {
        if (nums[i] > 0) break;
        int left = i + 1;
        int right = n - 1;
        int ret = -nums[i];
        while (left < right)
        {
            if (nums[left] + nums[right] > ret) right--;
            else if (nums[left] + nums[right] < ret) left++;
            else
            {
                V.push_back({ nums[i],nums[left],nums[right] });
                right--;
                while (right > left && nums[right + 1] == nums[right]) right--;
                left++;
                while (right > left && nums[left - 1] == nums[left]) left++;
            }
        }
        i++;
        while (i < n - 1 && nums[i - 1] == nums[i]) i++;
    }
    return V;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int t = 0;

    set<vector<int>> S;
    while (nums[t] <= 0 && t < nums.size() - 1)
    {
        int ret = -nums[t];
        int left = t + 1;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] > ret)
            {
                right--;
            }
            else if (nums[left] + nums[right] < ret)
            {
                left++;
            }
            else
            {
                vector<int> v({ nums[t],nums[left],nums[right] });
                S.insert(v);
                right--;
                left++;
            }
        }
        t++;
    }
    vector<vector<int>> V(S.begin(), S.end());
    return V;
}