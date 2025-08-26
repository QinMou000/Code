class Solution {
  public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hash1;
        unordered_set<int> hash2;
        for (auto e : nums1)
            hash1.insert(e);
        vector<int> ans;
        for (auto e : nums2)
            if (hash1.count(e)) {
                ans.push_back(e);
                hash1.erase(e); // 为了去重
            }
        return ans;
    }
};