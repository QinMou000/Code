#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;


int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0;
    int right = left;
    int sum = nums[right];
    int len = INT_MAX;
    while (right < nums.size() - 1)
    {
        while (sum >= target)
        {
            if (right - left + 1 < len)
                len = right - left + 1;
            sum -= nums[left];
            left++;
        }
        right++;
        sum += nums[right];
    }
    return len == INT_MAX ? 0 : len;
}

int main()
{


	return 0;
}