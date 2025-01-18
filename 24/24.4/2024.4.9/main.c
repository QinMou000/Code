#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

//void test1(void)
//{
//	STL_Node* phead = NULL;
//	SLTPushBack(&phead,1);
//	SLTPushBack(&phead, 1);
//	SLTPushBack(&phead, 1);
//	SLTPushBack(&phead, 1);
//	SLTPushFront(&phead, 2);
//	SLTPushFront(&phead, 2);
//	SLTPushFront(&phead, 2);
//	SLTPushFront(&phead, 2);
//
//	SLTPopBack(&phead);
//	SLTPopFront(&phead);
//
//	SLTPrint(phead);
//	SLTPrint(SLTFind(phead, 1));
//
//
//	SLTInsert(&phead, SLTFind(phead, 1),8);
//	SLTPrint(phead);
//
//	SLTInsertAfter(SLTFind(phead, 8), 9);
//	SLTPrint(phead);
//
//	SLTErase(&phead, SLTFind(phead, 9));
//	SLTPrint(phead);
//
//	SLTEraseAfter(SLTFind(phead, 8));
//	SLTPrint(phead);
//
//	SListDesTroy(&phead);
//	SLTPrint(phead);
//
//}

void test2(void)
{
	contact* phead = NULL;
	InitContact(&phead);
	AddContact(&phead);
	AddContact(&phead);
	ShowContact(phead);

	ModifyContact(&phead);
	ShowContact(phead);

	DelContact(&phead);
	ShowContact(phead);

	//ShowContact(phead);
	//ShowContact(FindContact(phead,"wq"));

	DestroyContact(&phead);
}


int main()
{

	//test1();
	test2();
	return 0;
}