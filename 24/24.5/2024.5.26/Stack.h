#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int StackDataType;

typedef struct stack
{
	StackDataType* data;
	int size;
	int capacity;
}Stack;

void StackInit(Stack* pst);

void StackDestory(Stack* pst);

void CheckCapacity(Stack* pst);

int StackIsEmpty(Stack* pst);

void StackPush(Stack* pst, StackDataType x);

void StackPop(Stack* pst);

StackDataType StackTop(Stack* pst);

int StackSize(Stack* pst);