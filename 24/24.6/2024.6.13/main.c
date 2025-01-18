#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(int* a, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] < a[child + 1] && child + 1 < n)
			child++;
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDown(a, i, n);
	for (int i = n - 1; i >= 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, 0, i);
	}
}

int main()
{
	int a[] = { 5,6,3,8,7,2,1,9,4 };
	HeapSort(a, sizeof(a) / sizeof(int));

	return 0;
}