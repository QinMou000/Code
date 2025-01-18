#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void _MergeSort(int* a,int* tmp, int left,int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;

	while (begin1 <= end1 && begin2 <= end2)//取等，剩最后一个数的时候也要尾插
	{
		if (a[begin1] >= a[begin2])
			tmp[i++] = a[begin2++];
		else
			tmp[i++] = a[begin1++];
	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	memcpy(a + left, tmp + left , sizeof(int) * (right - left + 1));
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

int main()
{
	int a[] = { 3,6,5,4,2,9,8,7,1 };
	MergeSort(a, sizeof(a) / sizeof(int));

	return 0;
}