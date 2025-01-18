#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}

void Destory(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	QNode* cur = pq->phead;
	while (pq->size)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
		pq->size--;
	}
	pq->ptail = pq->phead = NULL;
	pq = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc is fail");
		return;
	}
	newnode->val = x;
	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	newnode->next = NULL;
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	if (pq->size == 1)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}