#define _CRT_SECURE_NO_WARNI
#include <stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* new = (BTNode*)malloc(sizeof(BTNode));
	if (new == NULL)
	{
		perror("malloc is fail");
		return NULL;
	}
	new->_data = a[(*pi)++];
	new->_left = BinaryTreeCreate(a, pi);
	new->_right = BinaryTreeCreate(a, pi);
	return new;
}

void BinaryTreeMidOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("#");
		return;
	}
	BinaryTreeMidOrder(root->_left);
	printf("%c", root->_data);
	BinaryTreeMidOrder(root->_right);
}

int main() {
	char s[100];
	gets(s);
	int i = 0;
	BTNode* root = BinaryTreeCreate(s, &i);
	BinaryTreeMidOrder(root);
	return 0;
}