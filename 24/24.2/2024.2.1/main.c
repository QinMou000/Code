#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int left_round(char* str,char *str2, int len)
{
	int k = len;
	if (k != 1)
	{
		char x = *str;
		int i = 0;
		int lens = strlen(str);
		for (i = 0; i < lens; i++)
		{
			*(str + i) = *(str + i + 1);
		}
		*(str + i - 1) = x;
		if (strcmp(str, str2) != 0)
		{
			return left_round(str, str2, k - 1);
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

int main()
{
	char s[] = "abcde";
	char s2[] = "cdeab";
	
	int ret = left_round(s, s2, strlen(s));
	printf("%d\n",ret);
	return 0;
}


#if 0
void reverse(char *str)
{
	char *left = str;
	char *right = str + strlen(str)-1;//不能传数组形式，也不能用sizeof
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		right--;
		left++;
	}
}

int main()
{
	char str[10000] = { 0 };
	gets(str);
	reverse(str);
	puts(str);

	return 0;
}
#endif