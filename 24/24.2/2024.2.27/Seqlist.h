#pragma once

#include<stdio.h>
#include<string.h>

#define N 10

typedef int	SQDataType;

typedef struct SeqList
{
	SQDataType* a;
	SQDataType size;   //有效数据个数
	SQDataType capacity//容量
}SL;

//typedef struct SeqList SL;

void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps, SQDataType x);
void SeqListPushFront(SL* ps, SQDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);
