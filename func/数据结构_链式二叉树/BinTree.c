#define _CRT_SECURE_NO_WARNINGS 1

#include"BinTree.h"
#include"Queue.h"

//方法一:
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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
//通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
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

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		free(*root);
		return;
	}
	//if ((*root)->_left == NULL && (*root)->_right == NULL)
	//{
	//	free(*root);
	//	*root = NULL;
	//	return;
	//}
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1)
		+ BinaryTreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点
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

// 二叉树前序遍历 
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
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	assert(root);
	Queue q;
	QueueInit(&q);
	QueuePush(&q,root);
	
	while (QueueSize(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->_data);

		if (front->_left)
			QueuePush(&q,front->_left);
		if(front->_right)
			QueuePush(&q,front->_right);
	}
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	assert(root);
	Queue q;
	QueueInit(&q);
	QueuePush(&q, root);

	while (QueueSize(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
			break;
		
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}
	while (QueueSize(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			Destory(&q);
			return false;
		}
	}
	return true;
}