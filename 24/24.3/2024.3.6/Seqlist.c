#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"

void SeqListInit(SLT* ps)
{
	assert(ps);//保证ps不为空
	//memset(ps->data, 0, sizeof(SQDataType) * 4);
	ps->data = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListDistory(SLT* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListPrint(SLT* ps)
{
	for (int i = 0; i < ps->size; i++)
		printf("%d ", ps->data[i]);
	printf("\n");
}

void SeqListCheckCapacity(SLT* ps)
{
	if (ps->size == ps->capacity)//满了扩容
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SQDataType* tmp = realloc(ps->data, newcapacity * sizeof(SQDataType));
		if (tmp == NULL)
		{
			printf("realloc is fail!\n");
			exit(-1);
		}
		else
		{
			ps->data = tmp;
			ps->capacity = newcapacity;
		}
	}
}

void SeqListPushBack(SLT* ps, SQDataType x)
{
	SeqListCheckCapacity(ps);

	ps->data[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SLT* ps, SQDataType x)
{
	SeqListCheckCapacity(ps);

	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[0] = x;
	ps->size++;
}

void SeqListPopBack(SLT* ps)
{
	assert(ps->size > 0);
	//ps->data[ps->size - 1] = 0;//有没有都无所谓，有效数据是用size来表示的
	ps->size--;
}

void SeqListPopFront(SLT* ps)
{
	assert(ps->size > 0);
	int start = 0;
	while (start <= ps->size)
	{
		ps->data[start] = ps->data[start + 1];
		start++;
	}
	ps->size--;
}

void SeqListInsert(SLT* ps,int pos, SQDataType x)
{
	assert(pos <= ps->size);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->data[end + 1] = ps->data[end];
		end--;
	}
	ps->data[pos - 1] = x;
	ps->size++;
}

void SeqListErase(SLT* ps, int pos) 
{
	assert(pos <= ps->size);
	int end = pos;
	while (end <= ps->size)
	{
		ps->data[end - 1] = ps->data[end];
		end++;
	}
	ps->size--;
}

int SeqListFind(SLT* ps, SQDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == x)
			return i;
	}
	return -1;
}

void SeqListModity(SLT* ps, int pos, SQDataType x)
{
	assert(pos < ps->size);
	ps->data[pos - 1] = x;
}