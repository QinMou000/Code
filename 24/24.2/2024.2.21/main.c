#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int fun(int n,int x)
{
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i <= 9)
		{
			if (i == x)
			{
				num++;
			}
		}
		else
		{
			int tmp = i;
			do
			{
				if (tmp % 10 == x)
				{
					num++;
				}
			} 
			while (tmp /=10,tmp != 0);
		}
	}
	return num;
}

int main()
{
	int n = 0;
	int x = 0;
	scanf("%d %d",&n,&x);
	int ret = fun(n,x);
	printf("%d\n",ret);
	return 0;
}

#if 0
int main()
{
	int a = 0;
	void* p = &a;
	float f = 0.1f;
	void* pf = &f;
	//*p = 10;
	//p = p + 1;
	return 0;
}
#endif 