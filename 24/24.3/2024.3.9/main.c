#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>

#if 0
size_t my_strlen(char* s)//计数器
{
	size_t count = 0;
	while (*(s++))
		count++;
	return count;
}

size_t my_strlen(char* s)//递归
{
	if (*s == '\0')
		return 0;
	else
		return my_strlen(++s) + 1;
}

size_t my_strlen(char* s)//指针-指针
{
	char* tmp = s;
	while (*(++s))
		;
	return s - tmp;
}


int main()
{
	char str[] = "abcdef";
	printf("%zd\n",my_strlen(str));
	return 0;
}

char* my_strcpy(char* s1, const char* s2)//模拟实现strcpy
{	
	assert(s1 && s2);
	char* tmp = s1;
	while (*(s1++) = *(s2++))
		;
	return tmp;
}

int main()
{
	char str[] = "abcdef";
	char str1[20];
	my_strcpy(str1, str);
	printf("%s",str1);
	return 0;
}
#endif
char* my_strcat(char* s1, const char* s2)//模拟实现strcat
{
	assert(s1&&s2);
	char* tmp = s1;
	while (s1++, *s1 != '\0')
		;
	while (*s1++ = *s2++)
		;
	return tmp;
}

int main()
{
	char str[] = "def";
	char str1[20] = "abc";
	my_strcat(str1, str);
	printf("%s", str1);
	return 0;
}

//int main()
//{
//	int n = 10;
//	char* pc = (char*)&n;
//	int* pi = &n;
//	printf("%p\n", &n);
//	printf("%p\n", pc);
//	printf("%p\n", pc + 1);
//	printf("%p\n", pi);
//	printf("%p\n", pi + 1);
//	return 0;
//}

