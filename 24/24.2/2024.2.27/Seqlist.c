#define _CRT_SECURE_NO_WARNINGS 1
#include<Seqlist.h>

void SeqListInit(SL* ps)
{
	memset(ps->a, 0, sizeof(SQDataType)*N);
	ps->size = 0;
}

void SeqListPushBack(SL* ps, SQDataType x)//
{
	if (ps->size>=N)
	{
		printf("SeqList is Full\n");
	}
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPushFront(SL* ps, SQDataType x);//β��
void SeqListPopBack(SL* ps);//ͷɾ
void SeqListPopFront(SL* ps);//βɾ