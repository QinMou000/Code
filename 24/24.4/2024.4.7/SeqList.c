#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

void SLInit(SL* ps)//初始化
{
	ps->Data = NULL;
	ps->capacity = ps->size = 0;
}

void SLDestroy(SL* ps)//销毁
{
	if (ps->Data)
		free(ps->Data);
	ps->Data = NULL;
	ps->size = ps->capacity = 0;
}

void SLPrint(SL ps)//打印 
{
	for (int i = 0; i < ps.size; i++)
		printf("%d ",ps.Data[i]);
	printf("\n");
}

void Check_Capacity(SL* ps)//扩容
{
	if (ps->capacity == ps->size)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SeqList_Datatype* tmp = (SeqList_Datatype*)realloc(ps->Data, sizeof(SeqList_Datatype) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc is fail!");
			exit(1);
		}
		ps->Data = tmp;
		ps->capacity = newcapacity;
	}
}

void SLPushBack(SL* ps, SeqList_Datatype x)//尾插
{
	assert(ps);
	Check_Capacity(ps);
	ps->Data[ps->size++] = x;
}

void SLPushFront(SL* ps, SeqList_Datatype x)//头插
{
	assert(ps);
	Check_Capacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->Data[i] = ps->Data[i - 1];
	}
	ps->Data[0] = x;
	ps->size++;
}

void SLPopBack(SL* ps)//尾删
{
	assert(ps);
	assert(ps->size);
	ps->size--;
}

void SLPopFront(SL* ps)//头删
{
	assert(ps);
	assert(ps->size);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->Data[i] = ps->Data[i + 1];
	}
	ps->size--;
}

void SLInsert(SL* ps, int pos, SeqList_Datatype x)//指定插入  pos是下标，不是第几个！
{
	assert(ps);
	Check_Capacity(ps);
	for (int i = ps->size; i > pos + 1; i--)
	{
		ps->Data[i] = ps->Data[i - 1];
	}
	ps->Data[pos] = x;
	ps->size++;
}

void SLErase(SL* ps, int pos)//指定删除
{
	assert(ps);
	for (int i = pos; i < ps->size; i++)
	{
		ps->Data[i] = ps->Data[i + 1];
	}
	ps->size--;
}

//int SLFind(SL* ps, SeqList_Datatype x)//查找
//{
//	assert(ps);
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (x == ps->Data[i])
//			return i;
//	}
//	return -1;
//}

void SeqListModity(SL* ps, int pos, SeqList_Datatype x)//修改
{
	assert(ps);
	assert(pos < ps->size);
	ps->Data[pos] = x;
}

