/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>& fun(TreeNode* root, vector<int>& ret)
    {
        if(root != nullptr)
        {
            fun(root->left, ret);
            fun(root->right, ret);
            if(root->val != 0)
                ret.push_back(root->val);
        }
        return ret;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        fun(root, ret);
        return ret;
    }
};
// @lc code=end

