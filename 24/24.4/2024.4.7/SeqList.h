#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Contact.h"

typedef PF SeqList_Datatype;

typedef struct SeqList
{
	SeqList_Datatype* Data;
	int size;
	int capacity;
}SL;

//顺序表初始化
void SLInit(SL* ps);
//顺序表的销毁
void SLDestroy(SL* ps);
void SLPrint(SL ps);

//头部插入删除  尾部插入删除
void SLPushBack(SL* ps, SeqList_Datatype x);
void SLPushFront(SL* ps, SeqList_Datatype x);
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

//指定位置之前插入/删除数据
void SLInsert(SL* ps, int pos, SeqList_Datatype x);
void SLErase(SL* ps, int pos);

//查找修改
int SLFind(SL* ps, SeqList_Datatype x);
void SeqListModity(SL* ps, int pos, SeqList_Datatype x);