#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

//char* my_strcat(char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	char* tmp = s1;
//	while (s1++ ,*s1 != '\0')
//		;
//	while (*s1++ = *s2++)
//		;
//	return tmp;
//}
//
//int main()
//{
//	char  str1[20] = "abcd";
//	char  str2[] = "efgh";
//	my_strcat(str1, str2);
//	printf("%s\n",str1);
//	return 0;
//}

int my_strcmp(const char* s1, const char* s2)
{
	assert(s1 && s2);
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}
	return *s1 - *s2;

}
int main()
{
	char  str1[] = "abcdefgh";
	char  str2[] = "cd";
	printf("%d\n", my_strcmp(str1, str2));
	return 0;
}

//char* my_strstr(const char* s1, const char* s2)
//{
//	assert(s1 && s2);
//	const char* str1 = NULL;
//	const char* str2 = NULL;
//	char* cur = s1;
//
//	if (*s2 == '\0')
//		return (char*)s1;
//
//	while (*cur)
//	{
//		str1 = cur;
//		str2 = s2;
//		while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)//这里不能用*str1++==*str2++!!!这里是判断不是赋值！！！
//		{
//			str1++;
//			str2++;
//		}
//		if (*str2 == '\0')
//		{
//			return cur;
//		}
//		cur++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char  str1[] = "abccccccccdefgh";
//	char  str2[] = "cd";
//	printf("%s\n", my_strstr(str1, str2));
//	return 0;
//}
