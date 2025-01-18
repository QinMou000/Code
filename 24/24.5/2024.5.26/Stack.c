#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void StackInit(Stack* pst)
{
	assert(pst);
	pst->capacity = pst->size = 0;
	pst->data = NULL;
}

void StackDestory(Stack* pst)
{
	assert(pst);
	pst->capacity = pst->size = 0;
	free(pst->data);
	pst->data = NULL;
	free(pst);
}

void CheckCapacity(Stack* pst)
{
	assert(pst);
	if (pst->capacity == pst->size)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		StackDataType* tmp = (StackDataType*)realloc(pst->data,sizeof(StackDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc is fail");
			return;
		}
		pst->data = tmp;
		pst->capacity = newcapacity;
	}
}

int StackIsEmpty(Stack* pst)
{
	return pst->size;
}

void StackPush(Stack* pst, StackDataType x)
{
	assert(pst);
	CheckCapacity(pst);
	pst->data[pst->size] = x;
	pst->size++;
}

void StackPop(Stack* pst)
{
	assert(pst && pst->size);
	pst->size--;
}

StackDataType StackTop(Stack* pst)
{
	assert(pst && pst->size);
	return pst->data[pst->size - 1];
}

int StackSize(Stack* pst)
{
	assert(pst);
	return pst->size;
}