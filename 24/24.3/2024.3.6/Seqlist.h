#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

typedef int SQDataType;

typedef struct SeqList
{
	SQDataType* data;
	int size;
	int capacity;
}SLT;

void SeqListPrint(SLT* ps);//打印
void SeqListInit(SLT* ps);//初始化
void SeqListDistory(SLT* ps);//销毁
void SeqListCheckCapacity(SLT* ps);//扩容
void SeqListPushBack(SLT* ps, SQDataType x);//尾插
void SeqListPushFront(SLT* ps, SQDataType x);//头插
void SeqListPopBack(SLT* ps);//尾删
void SeqListPopFront(SLT* ps);//头删
void SeqListInsert(SLT* ps, int pos, SQDataType x);//指定插入
void SeqListErase(SLT* ps, int pos);//指定删除
int SeqListFind(SLT* ps, SQDataType x);//查找(返回下标)
void SeqListModity(SLT* ps,int pos,SQDataType x);//修改