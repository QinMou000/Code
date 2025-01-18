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

void QueueInit(Queue* pq);//���г�ʼ��

void Destory(Queue* pq);//���ٶ���

void QueuePush(Queue* pq, QDataType x);//���

void QueuePop(Queue* pq);//����

int QueueSize(Queue* pq);//��ö���Ԫ�ظ���

QDataType QueueFront(Queue* pq);//ȡ����ͷ��Ԫ��

QDataType QueueBack(Queue* pq);//ȡ����β��Ԫ��