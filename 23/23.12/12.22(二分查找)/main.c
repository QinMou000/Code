#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int bin_search(int arr[], int left, int right, int key)
{
	int mid;
	while(1)
	{
		mid = (left + right) / 2;
		if (arr[mid]>key)
		{
			if (right == mid)
			{
				printf("������ֲ����ڵ�ǰ�����У�\n");
				return -1;
				break;
			}
			right = mid;
		}
		else if (arr[mid]<key)
		{
			left = mid;
			if (left == mid)
			{
				printf("������ֲ����ڵ�ǰ�����У�\n");
				return -1;
				break;
			}
		}
		else if (arr[mid]==key)
		{
			return  mid;
			break;
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int root;
	printf("������Ҫ���ҵ�����");
	scanf("%d", &root);
	int ret=bin_search(arr, 0, 8, root);
	printf("����ֵΪ�� % d\n",ret);

	return 0;
}