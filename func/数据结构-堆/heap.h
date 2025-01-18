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

//堆的初始化
void HeapInit(HP* php);

// 堆的销毁
void HeapDestory(HP* php);

// 堆的插入
void HeapPush(HP* php, HPDataType x);

// 堆的删除
void HeapPop(HP* php);

// 取堆顶的数据
HPDataType HeapTop(HP* php);

// 堆的数据个数
int HeapSize(HP* php);

// 堆的判空
int HeapEmpty(HP* php);

void AdjustDown(HPDataType* a, int size, int parent);

void Swap(HPDataType* x, HPDataType* y);

