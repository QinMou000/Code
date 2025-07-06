// 给定两个整数数组nums1,nums2
// 找到他们的公共元素并返回
#include <unordered_map>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums1 int整型vector 
     * @param nums2 int整型vector 
     * @return int整型vector
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash;
        vector<int> ans;
        for(auto e : nums1)
            hash.insert(e);
        for(auto e : nums2)
        {
            if(hash.count(e))
            {
                ans.push_back(e);
                hash.erase(e);
            }
        }
        return ans;
    }
};