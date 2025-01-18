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

//˳����ʼ��
void SLInit(SL* ps);
//˳��������
void SLDestroy(SL* ps);
void SLPrint(SL ps);

//ͷ������ɾ��  β������ɾ��
void SLPushBack(SL* ps, SeqList_Datatype x);
void SLPushFront(SL* ps, SeqList_Datatype x);
void SLPopBack(SL* ps);
void SLPopFront(SL* ps);

//ָ��λ��֮ǰ����/ɾ������
void SLInsert(SL* ps, int pos, SeqList_Datatype x);
void SLErase(SL* ps, int pos);

//�����޸�
int SLFind(SL* ps, SeqList_Datatype x);
void SeqListModity(SL* ps, int pos, SeqList_Datatype x);