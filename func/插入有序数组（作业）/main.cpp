#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a;
	int arr1[8] = { 1,2,4,4,5,10,12 };//��������
	int arr2[8] = { 1,2,4,4,5,10,12 };//��������
	int length = sizeof(arr1) / sizeof(arr1[0]);//�������鳤��
	//printf("%d ", length);

	for (int i = 0; i < length-1; i++)//�����ʼ����
	{
		printf("%d ", arr1[i]);
	}

	printf("\n");
	scanf("%d",&a);//��������

	if (arr1[6] > a)
	{
		for (int i = 0; i < length; i++)//����arr1�и���Ԫ��
		{
			if (a < arr1[i])//�Ƚϣ����a<arr1[i]�ͽ�arr1[i]�滻��a�������Ԫ�����κ���һλ
			{
				arr1[i] = a;
				for (int j = i + 1; j < length; j++)
				{
					arr1[j] = arr2[i];//ע������������ñ�������arr2�Ļ������ᵼ��arr1[i]�����Ԫ��ȫ������a
					i++;
				}
			}
		}
	}

	else//��a��ֵ��arr1�����һλԪ��
	{
		arr1[7] = a;
	}

	for (int i = 0; i < length; i++)//���arr1�е�����Ԫ��
	{
		printf("%d ", arr1[i]);
	}

	printf("\n");
}