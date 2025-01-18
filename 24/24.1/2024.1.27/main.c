#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void init(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		arr[i] = 0;
	}
}

void print(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void reverse(int arr[], int count)
{
	int backup[1000] = { 0 };
	for (int i = 0; i < count; i++)
	{
		backup[i] = arr[i];
	}
	for (int i = 0; i < count; i++)
	{
		arr[i] = backup[count - 1 - i];
	}
}

int main()
{
	int arr_c[10] = { 0,1,2,3,4,5,6,7,8,9 };

	print(arr_c, 10);

	init(arr_c, 10);

	print(arr_c, 10);

	for (int i = 0; i < 10; i++)
	{
		arr_c[i] = i;
	}

	reverse(arr_c, 10);

	print(arr_c, 10);

	return 0;
}

#if 0

int main()
{
	printf("%zd\n",sizeof(int ));
	return 0;
}

int main()
{
	int num = 0;
	scanf("%d",&num);
	int nums = num;
	printf("奇数序列：");
	nums = nums >> 1;
	while (nums)
	{
		if ((nums & 1) == 1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		nums = nums >> 2;
	}
	printf("\n");
	printf("偶数序列：");
	while (num)
	{
		if ((num & 1) == 1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		num = num >> 2;
	}
	return 0;
}

int fun(int arr[], int len)
{
	int root = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (arr[i] == arr[j])
			{
				arr[i] = 0;
				arr[j] = 0;
				break;
			}
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (arr[i] != 0)
		{
			root = arr[i];
		}
	}
	return root;
}

int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4 };
	int len = sizeof(arr) / sizeof(arr[0]);

	int ret = fun(arr, len);
	printf("%d\n",ret);
	return 0;
}

#endif