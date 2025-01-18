#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"


void STInit(ST* pst)
{
	assert(pst);
	pst->capacity = 0;
	pst->top = 0;   //指向栈顶数据的下一个位置
	pst->data = NULL;
}

void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->data);
	pst->data = NULL;
	pst->capacity = pst->top = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);
	if (pst->capacity == pst->top)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;

		STDataType* tmp = (STDataType*)realloc(pst->data, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc is fail");
			return;
		}
		pst->data = tmp;
		pst->capacity = newcapacity;
		//free(tmp);   //因为pst和tmp的指向是一样的，不能释放掉开辟的空间，会导致野指针
	}
	pst->data[pst->top] = x;
	pst->top++;
}

void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	return pst->data[pst->top - 1];
}

bool STEmpty(ST* pst)
{
	assert(pst);
	return !pst->top;
}

int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}
