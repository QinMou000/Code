#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void CreateNDate()
{
	// ������
	int n = 100000;
	srand((int)time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void Swap(int* x, int* y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustDown(int* a, int size, int parent)
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

void PrintTopK()
{
	int k;
	scanf("%d", &k);
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}
	int* a = (int*)malloc(sizeof(int) * k);
	if (a == NULL)
	{
		perror("malloc is fail");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout,"%d",&a[i]);
	}
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, k,i);
	}
	int x;
	while(fscanf(fout, "%d", &x) > 0)
	{
		if (x > a[0])
		{
			a[0] = x;
			AdjustDown(a, k, 0);
		}
	}
	printf("����ǰ%d����:",k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}


int main()
{
	//CreateNDate();
	PrintTopK();
	return 0;
}