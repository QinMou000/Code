#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
/*密码强度有一定要求：

1. 密码只能由大写字母，小写字母，数字构成；

2. 密码不能以数字开头；

3. 密码中至少出现大写字母，小写字母和数字这三种字符类型中的两种；

4. 密码长度至少为8

现在小明受到了n个密码，他想请你写程序判断这些密码中哪些是合适的，哪些是不合法的
*/
{
	int num = 0;
	scanf("%d",&num);
	do
	{
		char str[100] = { 0 };
		scanf("%s", &str);
		int len = strlen(str);
		int flag = 0;
		int ret = 0;
		if (len >= 8 && (str[0] < 48 || str[0] > 57))
		{
			for (int i = 0; i < len; i++)
			{
				if (str[i] >= '0' && str[i] <= '9' && str[i] >= 'A' && str[i] <= 'Z' && str[i] >= 'a' && str[i] <= 'z')
				{

					flag = 1;
				}

			}
			if (flag = 1)
			{
				for (int i = 0; i < len; i++)
				{
					if (str[i] >= '0' && str[i] <= '9')
					{
						ret++;
					}
					if (str[i] >= 'A' && str[i] <= 'Z')
					{
						ret++;
					}
					if (str[i] >= 'a' && str[i] <= 'z')
					{
						ret++;
					}
				}
				if (ret >= 2)
				{
					printf("yes\n");
				}
				else
				{
					printf("no\n");
				}
			}
			else
			{
				printf('no\n');
			}
		}
		else
		{
			printf("no\n");
		}
		num--;
	} while (num);

	return 0;
}