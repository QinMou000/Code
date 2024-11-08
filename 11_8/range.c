#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

bool fun(int* arr, int x,int len)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == x)
			return false;
	}
	return true;
}

int main()
{
	int input = 0;
	do {
		int x, y;
		printf("范围：\n");
		scanf("%d%d", &x, &y);
		if (x > y)
		{
			perror("输入错误");
			return 0;
		}
		int n = y - x + 1;
		srand((unsigned int)time(NULL));
		int* arr = NULL;
		arr = (int*)realloc(arr, sizeof(int) * 1000);
		printf("顺序：\n");
		for (int i = 0; i < n; i++)
		{
			int ans;
			do
			{
				ans = rand() % y + 1;
			} while (ans < x || !fun(arr, ans, n));
			printf("%d ", ans);
			arr[i] = ans;
		}
		printf("\n是否再来一次？1/0\n");
		scanf("%d", &input);
	} while (input);
    return 0;
}
