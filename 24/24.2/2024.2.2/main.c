#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void find_killer()
{
	for (char killer = 'A'; killer <= 'D'; killer++)
	{
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		{
			printf("凶手是:%c\n",killer);
		}
	}

}

int main()
{
	find_killer();
	return 0;
}

#if 0
int finf_num(int arr[][3], int x, int y, int key)
{
	int i = 0;
	int j = y - 1;
	while (i < x &&j >= 0)//合法的i，j
	{
		if (arr[i][j] < key)
		{
			i++;
		}
		else if (arr[i][j] > key)
		{
			j--;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int ret = finf_num(arr,3,3,4);
	printf("%d\n",ret);
	return 0;
}
#endif