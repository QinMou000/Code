#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void test1(void)
{
	LTNode* phead = LTInit();
	LTPushBack(phead, 1);
	LTPushBack(phead, 2);
	LTPushBack(phead, 3);
	LTPushBack(phead, 4);
	LTPrint(phead);

	LTPopBack(phead);
	LTPrint(phead);

	LTPushFront(phead, 4);
	LTPushFront(phead, 3);
	LTPushFront(phead, 2);
	LTPushFront(phead, 1);
	LTPrint(phead);

	LTErase(LTFind(phead, 1));
	LTPrint(phead);

	LTInsert(LTFind(phead, 1), 5);
	LTPrint(phead);

	LTDestroy(phead);
}

int main()
{
	test1();
	return 0;
}