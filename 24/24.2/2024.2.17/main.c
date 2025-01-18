#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void find_num(int arr[], int len, int* pnum1, int* pnum2)
{
	int tmp = 0;
	//�����������������
	for (int i = 0; i < len; i++)
	{
		tmp ^= arr[i];
	}
	//�ҵ�tmp�ж�����Ϊ1��ĳһλk
	int k = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((tmp >> i) & 1 != 0)
		{
			k = i;
			break;
		}
	}
	//�������� ��ÿ������ ��kλ��1�ķֵ�һ���飬�����ֵ�浽pnum1��2
	*pnum1 = *pnum2 = 0;
	for (int i = 0; i < len; i++)
	{
		if (((arr[i] >> k) & 1) != 0)
		{
			//��kλ��1
			*pnum1 ^= arr[i];
		}
		else
		{
			//��kλ��0
			*pnum2 ^= arr[i];
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int num1 = 0;
	int num2 = 0;
	find_num(arr, len, &num1, &num2);
	printf("%d %d",num1,num2);
	return 0;
}