#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int i, j, a;
	printf("������Ҫ��ӡ�ĳ˷��ھ������������");
	scanf("%d", &a);
	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= a; j++)
			if (j <= i)
				printf("%d*%d=%d\t", j, i, i * j);
		printf("\n");
	}
	return 0;
}