#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int Midofthree(int* a, int x, int y, int z)
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

void QucikSort(int* a,int left,int right)
{
	if (left >= right)
		return;
	int x = Midofthree(a, left, right, (left + right) / 2);//��ֹʱ�临�Ӷ��˻�
	Swap(&a[x], &a[left]);
	int key = a[left];
	int begin = left, end = right;
	while (begin < end)
	{
		while (begin < end && key <= a[end])//���ұ���С
			end--;

		while (begin < end && key >= a[begin])//������Ҵ�
			begin++;

		Swap(&a[end], &a[begin]);//����
	}
	Swap(&a[left], &a[begin]);//��key�����м�
	QucikSort(a, left, begin - 1);//�ݹ�
	QucikSort(a, begin + 1, right);
}


int main()
{
	int a[] = { 2,5,6,9,8,1,4,7,3 };
	QucikSort(a, 0, 8);
	return 0;
}