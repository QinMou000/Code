#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

void QueueInit(Queue* pq);//队列初始化

void Destory(Queue* pq);//销毁队列

void QueuePush(Queue* pq, QDataType x);//入队

void QueuePop(Queue* pq);//出队

int QueueSize(Queue* pq);//获得队列元素个数

QDataType QueueFront(Queue* pq);//取出队头的元素

QDataType QueueBack(Queue* pq);//取出队尾的元素