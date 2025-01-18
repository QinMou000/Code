#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

void Print(int* a, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = n; i > 0; i--)
	{
		int prev = 0;
		int cur = 1;
		int falg = 1;
		while (cur < i)
		{
			if (a[prev] > a[cur])
			{
				falg = 0;
				Swap(&a[prev], &a[cur]);
			}
			prev = cur;
			cur++;
		}
		if (falg == 1)
			break;
	}
}

void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child] < a[child + 1] && child + 1 < n)
			child++;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

//堆排序
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)// 从最后一个非叶子节点开始
		AdjustDown(a, n, i);
	for (int i = n - 1; i > 0; i--)
	{
		Swap(&a[0], &a[i]);
		AdjustDown(a, i, 0);
	}
}

//插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > a[end + gap])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}

//选择排序
void SelectSort(int* a, int n)
{
	int start = 0;
	int end = n - 1;
	while (end > start)
	{
		int mini = start;
		int maxi = end;
		for (int i = start; i <= end; i++)
		{
			if (a[mini] > a[i])
				mini = i;
			if (a[maxi] < a[i])
				maxi = i;
		}
		if (mini == end)
		{
			Swap(&a[maxi], &a[end]);
			mini = maxi;
			Swap(&a[mini], &a[start]);
		}
		else
		{
			Swap(&a[maxi], &a[end]);
			Swap(&a[mini], &a[start]);
		}
		end--;
		start++;
	}
}

int Midofthree(int* a,int x, int y, int z)
{
	if (a[x] > a[y])
		if (a[x] > a[z])
			if (a[y] > a[z])
				return y;
			else
				return z;
		else
			return y;
	else//a<b
		if (a[x] < a[z])
			if (a[y] < a[z])
				return y;
			else//b>c
				return z;
		else//a>c
			return x;
}

//hoare版本
int partsort1(int* a, int left, int right)
{

	int begin = left, end = right;
	int x = Midofthree(a, left, right, (right + left) / 2);
	Swap(&a[x], &a[left]);
	int key = left;
	while (begin < end)
	{
		while (begin < end)
		{
			if (a[end] < a[key])
				break;
			end--;
		}
		while (begin < end)
		{
			if (a[begin] > a[key])
				break;
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[key], &a[begin]);
	return begin;
}

//双指针版本
int partsort2(int* a, int left, int right)
{
	int x = Midofthree(a, left, right, (right + left) / 2);
	Swap(&a[x], &a[left]);
	int keyi = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[cur], &a[prev]);
		cur++;
	}
	Swap(&a[prev],&a[keyi]);
	return prev;
}

//挖坑版本
int partsort3(int* a, int left, int right)
{
	int x = Midofthree(a, left, right, (right + left) / 2);
	Swap(&a[x], &a[left]);
	int key = a[left];
	int pit = left;
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (a[end] >= key && begin < end)
			end--;

		a[pit] = a[end];
		pit = end;

		while (a[begin] <= key && begin < end)
			begin++;
		
		a[pit] = a[begin];
		pit = begin;
	}
	a[pit] = key;
	return pit;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);//小区间优化
		return;
	}

	int keyi = partsort1(a, left, right);

	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

void QuickSortNonR(int* a, int left, int right)
{
	ST s;
	STInit(&s);
	STPush(&s, right);
	STPush(&s, left);

 	while (!STEmpty(&s))
	{
		int begin = STTop(&s);
		STPop(&s);
		int end = STTop(&s);
		STPop(&s);

		int mid = partsort1(a, begin, end);
		if (mid + 1 < end)//注意这里需判断
		{
			STPush(&s, end);
			STPush(&s, mid + 1);
		}
		if (begin < mid - 1)//注意这里需判断
		{
			STPush(&s, mid - 1);
			STPush(&s, begin);
		}
	}
}

void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if(a[begin1] <= a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];

	while (begin2 <= end2)
		tmp[i++] = a[begin2++];

	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}


void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc is fail");
		return;
	}
	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc is fail");
		return;
	}
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;
			int j = i;
			if (begin2 >= n)
				break;
			if (end2 >= n)
				end2 = n - 1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
					tmp[j++] = a[begin1++];
				else
					tmp[j++] = a[begin2++];
			}
			while (begin1 <= end1)
				tmp[j++] = a[begin1++];

			while (begin2 <= end2)
				tmp[j++] = a[begin2++];

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
	free(tmp);
	tmp = NULL;
}

void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* x = (int*)calloc(range, sizeof(int));
	if (x == NULL)
	{
		perror("calloc is fail");
		return;
	}
	for (int i = 0; i < n; i++)
		x[a[i] - min]++;

	int j = 0;
	for (int i = 0; i < n; i++)
		while (x[i]--)
			a[j++] = i + min;

	free(x);
}