
#include<stdio.h>
int main()
{
	int big, mid, small, sum = 0;
	for (big = 0; big < 33; big++)
	{
		for (small = 0; small < 100; small += 2)
		{
			for (mid = 0; mid < 50; mid++)
			{
				if (3 * big + 2 * mid + small / 2 == 100 && big + mid + small == 100)
				{
					printf("����:%d\t����:%d\tС��:%d\n", big, mid, small);
					sum++;
				}
			}
		}
	}
	printf("����%d�ֿ���\n",sum);
	return 0;
}
