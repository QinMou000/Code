#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void heaptest()
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

int main()
{
	heaptest();
	return 0;
}