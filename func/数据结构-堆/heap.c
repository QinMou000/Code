#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

//�ѵĳ�ʼ��
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}

// �ѵ�����
void HeapDestory(HP* php)
{
	free(php->a);
	php->capacity = php->size = 0;
	free(php);
}

//����
void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

//���ϵ���
void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0 && a[parent] > a[child])//С��
	{
		Swap(&a[parent], &a[child]);
		child = parent;
		parent = (child - 1) / 2;
	}
}

// �ѵĲ���
void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)//��������
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
	while (child < size)//���ﲻ����up���ֶ�д��һ��
	{
		if (a[child] > a[child + 1] && child + 1 < size)//&&����Ķ�������Ҫ������
			child++;
		if (a[parent] > a[child])//child�仯֮�����жϡ�
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

// �ѵ�ɾ��
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&(php->a[0]), &(php->a[php->size - 1]));
	php->size--;

	AdjustDown(php->a, php->size - 1, 0);
}

// ȡ�Ѷ�������
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

// �ѵ����ݸ���
int HeapSize(HP* php)
{
	assert(php);
	return php->size - 1;
}

// �ѵ��п�
int HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}