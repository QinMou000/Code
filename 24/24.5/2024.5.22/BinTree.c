#define _CRT_SECURE_NO_WARNINGS 1

#include"BinTree.h"
//����һ:
//// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
//BTNode* BinaryTreeCreate(BTDataType* a,int* pi)
//{
//	if (a[*pi] == '#')
//	{
//		(*pi)++;
//		return NULL;
//	}
//	BTNode* new = (BTNode*)malloc(sizeof(BTNode));
//	if (new == NULL)
//	{
//		perror("malloc is fail");
//		return NULL;
//	}
//	new->_data = a[(*pi)++];
//	new->_left = BinaryTreeCreate(a, pi);
//	new->_right = BinaryTreeCreate(a, pi);
//	return new;
//}
//������:���ô�pi��ֻ��һ���ַ�������~
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType** a)
{
	char** s = a;
	if (**s == '#')
	{
		(*s)++;
		return NULL;
	}
	BTNode* new = (BTNode*)malloc(sizeof(BTNode));
	if (new == NULL)
	{
		perror("malloc is fail");
		return NULL;
	}
	new->_data = **s;
	(*s)++;
	new->_left = BinaryTreeCreate(s);
	new->_right = BinaryTreeCreate(s);
	return new;
}

// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
		return;
	if ((*root)->_left == NULL && (*root)->_right == NULL)
	{
		free(*root);
		*root = NULL;
		return;
	}
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1)
		+ BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* ret1 = BinaryTreeFind(root->_left, x);
	if (ret1 != NULL)
		return ret1;
	return BinaryTreeFind(root->_right, x);	
}

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{	
		printf("# ");
		return;
	}
	printf("%c ",root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	//����˼·��������������ݶ��Ž��������棬��˳��ṹ�жϡ�
}