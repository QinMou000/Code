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

//β��
void SLTPushBack(STL_Node** pphead, SList_Datatype x);
//ͷ��
void SLTPushFront(STL_Node** pphead, SList_Datatype x);
//βɾ
void SLTPopBack(STL_Node** pphead);
//ͷɾ
void SLTPopFront(STL_Node** pphead);

//����
//STL_Node* SLTFind(STL_Node* phead, SList_Datatype x);

//��ָ��λ��֮ǰ��������
void SLTInsert(STL_Node** pphead, STL_Node* pos, SList_Datatype x);
//��ָ��λ��֮���������
void SLTInsertAfter(STL_Node* pos, SList_Datatype x);

//ɾ��pos�ڵ�
void SLTErase(STL_Node** pphead, STL_Node* pos);
//ɾ��pos֮��Ľڵ�
void SLTEraseAfter(STL_Node* pos);

//��������
void SListDesTroy(STL_Node** pphead);