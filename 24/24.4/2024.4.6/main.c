#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>

long long pickGifts(int* gifts, int giftsSize, int k)
{
	if (k == 0)
	{
		long long sum = 0;
		for (int i = 0; i < giftsSize; i++)
		{
			sum += *(gifts + i);
		}
		return sum;
	}
	else
	{
		long long pos;
		long long max = 0;
		for (int i = 0; i < giftsSize; i++)
		{
			if (*(gifts + i) > max)
			{
				max = *(gifts + i);
				pos = i;
			}
		}
		*(gifts + pos) = (long long)sqrt(*(gifts + pos));
		return pickGifts(gifts, giftsSize, --k);
	}
}

int main()
{
	long long gifts[] = { 25,64,9,4,100};
	int len = sizeof(gifts) / sizeof(gifts[0]);
	printf("%d\n",(int)pickGifts(gifts, len, 4));
	return 0;
}