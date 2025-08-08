class Solution {
  public:
    int ans =  -1001;
    int maxPathSum(TreeNode* root) {
        // 后序遍历
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root) {
        if (root) {
            // 含根节点的最大单链和
            int l = max(dfs(root->left), 0);
            int r = max(dfs(root->right), 0);
            // 整理经过当前节点的最大路径和 更新结果
            ans = max(root->val + l + r, ans);
            // 往上层交以当前节点为根的最大单链和
            return root->val + max(l, r);
        } else return 0;
    }
};

// link : https://www.nowcoder.com/practice/8fda1d22554f4824b0ef9c26f35e54dd