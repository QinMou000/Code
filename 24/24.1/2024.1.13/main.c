#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main()
/*����ǿ����һ��Ҫ��

1. ����ֻ���ɴ�д��ĸ��Сд��ĸ�����ֹ��ɣ�

2. ���벻�������ֿ�ͷ��

3. ���������ٳ��ִ�д��ĸ��Сд��ĸ�������������ַ������е����֣�

4. ���볤������Ϊ8

����С���ܵ���n�����룬��������д�����ж���Щ��������Щ�Ǻ��ʵģ���Щ�ǲ��Ϸ���
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