#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//void SLTPrint(STL_Node* phead)
//{
//	STL_Node* pur = phead;
//	while (pur)
//	{
//		printf("%d->", pur->Data);
//		pur = pur->Next;
//	}
//	printf("NULL\n");
//}

STL_Node* SLTBuyNode(SList_Datatype x)
{
	STL_Node* newnode = (STL_Node*)malloc(sizeof(STL_Node));
	if (newnode == NULL)
	{
		perror("malloc is fail!");
		exit(1);
	}
	newnode->Data = x;
	newnode->Next = NULL;
	return newnode;
}

void SLTPushBack(STL_Node** pphead, SList_Datatype x)
{
	assert(pphead);
	STL_Node* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		STL_Node* ptail = *pphead;
		while (ptail->Next)
		{
			ptail = ptail->Next;
		}
		ptail->Next = newnode;
	}
}

void SLTPushFront(STL_Node** pphead, SList_Datatype x)
{
	assert(pphead);
	STL_Node* newnode = SLTBuyNode(x);
	newnode->Next = *pphead;
	*pphead = newnode;
}

void SLTPopBack(STL_Node** pphead)
{
	assert(pphead&&*pphead);
	if ((*pphead)->Next == NULL)
	{
		free(pphead);
		pphead = NULL;
	}
	STL_Node* prve = *pphead;
	STL_Node* ptail = *pphead;
	while (ptail->Next)
	{
		prve = ptail;
		ptail = ptail->Next;
	}
	free(ptail);
	ptail = NULL;
	prve->Next = NULL;
}

void SLTPopFront(STL_Node** pphead)
{
	assert(pphead&&*pphead);
	STL_Node* tmp = (*pphead)->Next;
	free(*pphead);
	*pphead = tmp;
}

//STL_Node* SLTFind(STL_Node* phead, SList_Datatype x)
//{
//	STL_Node* pur = phead;
//	while (pur)
//	{
//		if (pur->Data == x)
//		{
//			return pur;
//		}
//		pur = pur->Next;
//	}
//	return NULL;
//}
//在指定位置之前插入数据
void SLTInsert(STL_Node** pphead, STL_Node* pos, SList_Datatype x)
{
	assert(pphead&&*pphead);
	assert(pos);
	STL_Node* newnode = SLTBuyNode(x);
	if (*pphead == pos)
	{
		SLTPushFront(pphead,x);
		free(newnode);
		newnode = NULL;
	}
	else
	{
		STL_Node* prve = *pphead;
		while (prve->Next != pos)
		{
			prve = prve->Next;
		}
		prve->Next = newnode;
		newnode->Next = pos;

	}
}
//在指定位置之后插入数据
void SLTInsertAfter(STL_Node* pos, SList_Datatype x)
{
	assert(pos);
	STL_Node* newnode = SLTBuyNode(x);
	newnode->Next = pos->Next;
	pos->Next = newnode;
}
//删除pos节点
void SLTErase(STL_Node** pphead, STL_Node* pos)
{
	assert(pphead&&*pphead);
	assert(pos);
	if (pos == *pphead)
		SLTPopFront(pphead);
	else
	{
		STL_Node* prev = *pphead;
		while (prev->Next != pos)
		{
			prev = prev->Next;
		}
		prev->Next = pos->Next;
		free(pos);
		pos = NULL;
	}
}
//删除pos之后的节点
void SLTEraseAfter(STL_Node* pos)
{
	assert(pos&&pos->Next);
	STL_Node* del = pos->Next;
	pos->Next = del->Next;
	free(del);
	del = NULL;
}
//销毁链表
void SListDesTroy(STL_Node** pphead)
{
	assert(pphead && *pphead);
	while (*pphead)
	{
		STL_Node* next = (*pphead)->Next;
		free(*pphead);
		*pphead = next;
	}
	*pphead = NULL;
}
