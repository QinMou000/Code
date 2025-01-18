#define _CRT_SECURE_NO_WARNINGS 1

#include"BinTree.h"

int main()
{
	char* s = "ABD##E#H##CF##G##";
	BTNode* root = BinaryTreeCreate(&s);
	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeSize:%d\n", BinaryTreeSize(root));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(root,3));
	BTNode* ans = BinaryTreeFind(root, 'a');
	if (ans == NULL)
		printf("此树中无此节点\n");
	else
		printf("BinaryTreeFind:%c\n", ans->_data);
	BinaryTreePrevOrder(root);
	BinaryTreeDestory(&root);
	return 0;
}