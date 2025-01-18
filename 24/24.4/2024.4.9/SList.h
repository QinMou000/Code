#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Contact.h"

typedef PeoInfo SList_Datatype;

typedef struct SList_Node
{
	SList_Datatype Data;
	struct SList_Node* Next;
}STL_Node;

//void SLTPrint(STL_Node* phead);

//尾插
void SLTPushBack(STL_Node** pphead, SList_Datatype x);
//头插
void SLTPushFront(STL_Node** pphead, SList_Datatype x);
//尾删
void SLTPopBack(STL_Node** pphead);
//头删
void SLTPopFront(STL_Node** pphead);

//查找
//STL_Node* SLTFind(STL_Node* phead, SList_Datatype x);

//在指定位置之前插入数据
void SLTInsert(STL_Node** pphead, STL_Node* pos, SList_Datatype x);
//在指定位置之后插入数据
void SLTInsertAfter(STL_Node* pos, SList_Datatype x);

//删除pos节点
void SLTErase(STL_Node** pphead, STL_Node* pos);
//删除pos之后的节点
void SLTEraseAfter(STL_Node* pos);

//销毁链表
void SListDesTroy(STL_Node** pphead);