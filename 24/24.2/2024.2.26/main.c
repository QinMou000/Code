#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>

//bool isValid(char* s)//错误代码！！明天去学校……
//{
//	for (int i = 0; s[i] != '\0'; i++)
//	{
//		for (int j = i+1; s[j] != '\0'; j++)
//		{
//			if (s[i] == '('&&s[i]+1==s[j])
//			{
//				for (int x = i; x <= j; x++)
//				{
//					s[x] = '1';
//				}
//			}
//			else if(s[i]+2==s[j])
//			{
//				for (int x=i;x<=j;x++)
//				{
//					s[x] = '1';
//				}
//			}
//		}
//	}
//	for (int i = 0; s[i] != '\0'; i++)
//	{
//		if (s[i] != '1')
//		{
//			return false;
//		}
//		else
//		{
//			return true;
//		}
//	}
//}

int main()
{
	char str[100000] = "([)]";
	printf("%d\n", isValid(str));
	return 0;
}

