/*
 * @lc app=leetcode.cn id=1419 lang=cpp
 *
 * [1419] 数青蛙
 */

// @lc code=start
class Solution
{
public:
    int minNumberOfFrogs(string croak)
    {
        string str = "croak";
        int n = str.size();
        vector<int> hash(n); // 用数组 代替hash

        unordered_map<char, int> index; // [s字符, 对应下标]

        for (int i = 0; i < n; i++)
            index[str[i]] = i; // 建立映射关系

        for (auto e : croak)
        {
            if (e == 'c')
            {
                if (hash[n - 1] != 0)
                    hash[n - 1]--;
                hash[0]++;
            }
            else
            {
                int cur = index[e];
                if (hash[cur - 1] == 0)
                    return -1;
                hash[cur - 1]--;
                hash[cur]++;
            }
        }
        for (int i = 0; i < n - 1; i++)
            if (hash[i] != 0)
                return -1;

        return hash[n - 1];
    }
};
// @lc code=end
