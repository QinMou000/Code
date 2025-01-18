#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int* selfDividingNumbers(int left, int right, int* returnSize)//俺不会~~~~~俺还有理~~~~~
{
	for (int i = left; i <= right; i++)
	{
		int j = 0;
		int iplus = i;
		for (; i != 0;i=i/10)
		{
			
			unsigned int ret = i % 10;
			if (ret != 0)
			{
				if (iplus % ret == 0)
				{
					continue;
				}
				else
				{
					if (i == 0)
					{
						returnSize[j] = iplus;
						j++;
					}
				}
			}
		}
	}
	return returnSize;
}

int main()
{
	int arr[] = { 0 };
	selfDividingNumbers( 100,130,arr);
	for (int i = 0; arr[i] != 0; i++)
	{
		printf("%zd ", &arr[i]);
	}
	return 0;
}
