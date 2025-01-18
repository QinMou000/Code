#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

LTNode* BuyNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc is fail!");
		exit(1);
	}
	node->data = x;
	node->prev = node->next = node;
	return node;
}

LTNode* LTInit()
{
	LTNode* phead = BuyNode(-1);
	return phead;
}

void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d->",pcur->data);
		pcur = pcur->next;
	}
	printf("\n");//注意换行
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyNode(x);
	newnode->prev = phead->prev;
	newnode->next = phead;

	newnode->prev->next = newnode;
	phead->prev = newnode;
}

void LTPopBack(LTNode* phead)
{
	assert(phead && phead->next != phead);//第二个很容易忽视！
	LTNode* del = phead->prev;
	del->prev->next = phead;
	phead->prev = del->prev;
	free(del);
	del = NULL;
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = BuyNode(x);
	phead->next->prev = newnode;
	newnode->next = phead->next;

	phead->next = newnode;
	newnode->prev = phead;
}

void LTPopFront(LTNode* phead)
{
	assert(phead && phead->next != phead);
	LTNode* del = phead->next;
	del->next->prev = phead;
	phead->next = del->next;
	free(del);
	del = NULL;
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead && phead->next != phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)//别忘了连等号！！！
			return pcur;
		pcur = pcur->next;
	}
	return NULL;
}

void LTErase(LTNode* pos)
{
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}

void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = BuyNode(x);
	pos->next->prev = newnode;
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next = newnode;
}

void LTDestroy(LTNode* phead)//理论上这里应该传二级指针，但是为了保持接口的一致性，用一级。
{
	assert(phead);
	LTNode* des = phead->next;
	while (des != phead)
	{
		LTNode* next = des->next;
		free(des);
		des = next;
	}
	free(phead);
	phead = des = NULL;
}