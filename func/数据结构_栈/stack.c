#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"


void STInit(ST* pst)
{
	assert(pst);
	pst->capacity = 0;
	pst->top = 0;   //ָ��ջ�����ݵ���һ��λ��
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
		//free(tmp);   //��Ϊpst��tmp��ָ����һ���ģ������ͷŵ����ٵĿռ䣬�ᵼ��Ұָ��
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
