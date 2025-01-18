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

void SeqListPrint(SLT* ps);//��ӡ
void SeqListInit(SLT* ps);//��ʼ��
void SeqListDistory(SLT* ps);//����
void SeqListCheckCapacity(SLT* ps);//����
void SeqListPushBack(SLT* ps, SQDataType x);//β��
void SeqListPushFront(SLT* ps, SQDataType x);//ͷ��
void SeqListPopBack(SLT* ps);//βɾ
void SeqListPopFront(SLT* ps);//ͷɾ
void SeqListInsert(SLT* ps, int pos, SQDataType x);//ָ������
void SeqListErase(SLT* ps, int pos);//ָ��ɾ��
int SeqListFind(SLT* ps, SQDataType x);//����(�����±�)
void SeqListModity(SLT* ps,int pos,SQDataType x);//�޸�