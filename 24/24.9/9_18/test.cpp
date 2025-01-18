#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<stack>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool truepath(TreeNode* t, TreeNode* x)
{
    if (t == nullptr)
        return false;
    
    if (t == x)
        return true;

    return truepath(t->left, x) || truepath(t->right, x);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if (root == nullptr)
        return nullptr;
    if (root == p || root == q)
        return root;
    if ((truepath(root->left, p) && truepath(root->right, q)) ||
        truepath(root->right, p) && truepath(root->left, q))
        return root;

    if (truepath(root->left, q))
        return lowestCommonAncestor(root->left, p, q);
    else
        return lowestCommonAncestor(root->right, p, q);
}



#if 0
class Solution {
public:

    bool getpath(TreeNode* t, TreeNode* x,stack<TreeNode*> path)
    {
        if (t == nullptr)
            return false;

        path.push(t);

        if (t == x)
            return true;

        else if (getpath(t->left, x, path))
            return true;
        else if(getpath(t->right, x, path))
            return true;
        else
        {
            path.pop();
            return false;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pPath, qPath;

        getpath(root, p, pPath);
        getpath(root, q, qPath);

        while (pPath.size() != qPath.size())
        {
            if (pPath.size() > qPath.size())
                pPath.pop();
            else
                qPath.pop();
        }

        while (pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();

    }
};
#endif