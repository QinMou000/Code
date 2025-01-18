#define _CRT_SECURE_NO_WARNINGS 1

#include"BinTree.h"

int main()
{
	char* s = "ABD##E#H##CF##G##";
	puts(s);
	BTNode* root = BinaryTreeCreate(&s);
	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeSize:%d\n", BinaryTreeSize(root));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(root,3));
	BTNode* ans = BinaryTreeFind(root, 'a');
	if (ans == NULL)
		printf("此树中无此节点\n");
	else
		printf("BinaryTreeFind:%c\n", ans->_data);
	printf("前序遍历:");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("中序遍历:");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("后序遍历:");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("层序遍历:");
	BinaryTreeLevelOrder(root);
	printf("\n");
	if(BinaryTreeComplete(root))
		printf("此树是完全二叉树\n");
	else
		printf("此树不是完全二叉树\n");
	BinaryTreeDestory(&root);
	return 0;
}