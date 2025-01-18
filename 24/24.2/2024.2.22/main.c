#define _CRT_SECURE_NO_WARNINGS 1
#define NDEBUG
#include<stdio.h>
#include<assert.h>

int main()
{
	int* p = NULL;
	assert(p!=NULL);
	return 0;
}

#if 0
int fun(int n,int * arr)
{
	for (int i = 0; i < n; i++)
	{
		scanf("%d", (arr + i));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (*(arr + i) < *(arr + j))
			{
				int tmp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = tmp;
			}
		}
	}
	return *arr - *(arr + n-1);
}

int main()
{
	int n = 0;
	scanf("%d",&n);
	int arr[10000] = { 0 };
	int ret = fun(n, arr);
	printf("%d\n", ret);
	return 0;
}

int fun(int n,int *arr)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", (arr + i));
	}
	for (int i = 0; i < n; i++)
	{
		sum += *(arr + i);
	}
	return sum;
}

int main()
{
	int n = 0;
	int arr[100000] = { 0 };
	scanf("%d", &n);
	int ret = fun(n,arr);
	printf("%d\n",ret);
	return 0;
}
#endif