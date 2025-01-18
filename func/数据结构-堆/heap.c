#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

//堆的初始化
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

// 堆的销毁
void HeapDestory(HP* php)
{
	free(php->a);
	php->capacity = php->size = 0;
	free(php);
}

//交换
void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0 && a[parent] > a[child])//小堆
	{
		Swap(&a[parent], &a[child]);
		child = parent;
		parent = (child - 1) / 2;
	}
}

// 堆的插入
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)//满了扩容
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = realloc(php->a, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			printf("realloc is fail!\n");
			exit(-1);
		}
		else
		{
			php->a = tmp;
			php->capacity = newcapacity;
		}
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a,php->size-1);
}

void AdjustDown(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)//这里不能像up部分都写到一起！
	{
		if (a[child] > a[child + 1] && child + 1 < size)//&&后面的东西很重要！！！
			child++;
		if (a[parent] > a[child])//child变化之后再判断。
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

// 堆的删除
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	php->size--;

	AdjustDown(php->a, php->size - 1, 0);
}

// 取堆顶的数据
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

// 堆的数据个数
int HeapSize(HP* php)
{
	assert(php);
	return php->size - 1;
}

// 堆的判空
int HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}