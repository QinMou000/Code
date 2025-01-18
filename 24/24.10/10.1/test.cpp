#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    int t = nums.size() - 1;
    while (t)
    {
        int left = 0;
        int right = t - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] > nums[t])
            {
                ans += right - left;
                right--;
            }
            else
            {
                left++;
            }
        }
        t--;
    }
    return ans;
}
int main()
{


	return 0;
}