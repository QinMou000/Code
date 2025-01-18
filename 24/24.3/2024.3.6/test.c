#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"
void SeqList1()
{
	struct SeqList sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListInsert(&sl, 6, 9);
	SeqListPrint(&sl);

	SeqListErase(&sl, 7);
	SeqListPrint(&sl);

	SeqListModity(&sl,2,18);
	SeqListPrint(&sl);

	printf("%d\n",SeqListFind(&sl,18));
	SeqListDistory(&sl);
}

int main()
{
	SeqList1();
	return 0;
}
