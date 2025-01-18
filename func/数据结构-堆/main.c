#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"
/*
void heaptest1()
{
	HP heap;
	HeapInit(&heap);
	int a[] = { 5,6,8,2,4,3,1,9,7 };
	int i = 0;
	while (i < sizeof(a)/sizeof(a[0]))
	{
		HeapPush(&heap, a[i]);
		i++;
	}
	for (int j = 0; j < 9; j++)
	{
		printf("%d ", HeapTop(&heap));
		HeapPop(&heap);
	}
}
*/
void heapsort(int* a,int n)//降序建小堆，升序建大堆
{
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

int main()
{
	int a[] = { 5,6,8,2,4,3,1,9,7 };
	heapsort(a,sizeof(a)/sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}