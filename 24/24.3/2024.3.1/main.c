#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

char* fun(int *a,int n)
{
	int i = 0;
	int flag;
	if (a[0] > a[1])
	{
		flag = 1;
		while (i < n-1)
		{
			if (a[i] < a[i+1])
			{
				flag = 0;
			}
			i++;
		}
	}
	else
	{
		flag = 1;
		while (i < n-1)
		{
			if (a[i] > a[i + 1])
			{
				flag = 0;
			}
			i++;
		}
	}
	if (flag)
		return "sorted";
	else
		return "unsorted";
}

int main()
{
	int n = 0;
	scanf("%d",&n);
	int arr[51] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("%s",fun(arr,n));
	return 0;
}