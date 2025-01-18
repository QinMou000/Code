#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
	int* a;
	int capacity;
	int size;
}HP;

//�ѵĳ�ʼ��
void HeapInit(HP* php);

// �ѵ�����
void HeapDestory(HP* php);

// �ѵĲ���
void HeapPush(HP* php, HPDataType x);

// �ѵ�ɾ��
void HeapPop(HP* php);

// ȡ�Ѷ�������
HPDataType HeapTop(HP* php);

// �ѵ����ݸ���
int HeapSize(HP* php);

// �ѵ��п�
int HeapEmpty(HP* php);

void AdjustDown(HPDataType* a, int size, int parent);

void Swap(HPDataType* x, HPDataType* y);

