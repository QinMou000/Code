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
		printf("�������޴˽ڵ�\n");
	else
		printf("BinaryTreeFind:%c\n", ans->_data);
	printf("ǰ�����:");
	BinaryTreePrevOrder(root);
	printf("\n");
	printf("�������:");
	BinaryTreeInOrder(root);
	printf("\n");
	printf("�������:");
	BinaryTreePostOrder(root);
	printf("\n");
	printf("�������:");
	BinaryTreeLevelOrder(root);
	printf("\n");
	if(BinaryTreeComplete(root))
		printf("��������ȫ������\n");
	else
		printf("����������ȫ������\n");
	BinaryTreeDestory(&root);
	return 0;
}