#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	int capacity;
	int top;
}ST;

void STInit(ST* pst);

void STDestroy(ST* pst);

void STPush(ST* pst, STDataType x);

void STPop(ST* pst);

STDataType STTop(ST* pst);

bool STEmpty(ST* pst);

int STSize(ST* pst);
