#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct BTreeNode
{
	int val;
	struct BTreeNode* left;
	struct BTreeNode* right;
}BTNode;

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return (root->left == NULL && root->right == NULL) ? 1 : 
		TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeLeafHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int height1 = TreeLeafHeight(root->left);
	int height2 = TreeLeafHeight(root->right);
	return height1 > height2 ?
		height1 + 1 : height2 + 1;
}

//求第k层的节点个数？
int TreeNumK(BTNode* root,int k)
{
	if (root == NULL)
		return 0;
	if (k != 1)
		return TreeNumK(root->left, k - 1) + TreeNumK(root->right, k - 1);
	if (k == 1)
		return 1;
}

int main()
{
	return 0;
}