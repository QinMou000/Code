#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>

void* my_memcpy(void* dest,void* sour,size_t num)
{
	assert(dest && sour);
	char* tmp = (char*)dest;
	if (dest == sour)
		return dest;
	else if (dest < sour)
	{
		while (num--)
		{
			*(((char*)dest)++) = *(((char*)sour)++);
		}
	}
	else
	{
		while (num--)
		{
			*(((char*) dest) + num) = *(((char*) sour) + num);
		}
	}
	return tmp;
}

int main()
{
	int arr1[1000] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[] = { 4,5,6 };
	my_memcpy(arr1+5, arr1,24);
	return 0;
}
#if 0
//模拟实现strncat
char* my_strncat(char* str1, char* str2, size_t num)
{
	assert(str1&&str2);
	char* tmp = str1;
	while (*str1!='\0')
		str1++;
	while ((*str1++ = *str2++) && --num)
		;
	if (num)
		while (num--)
			*str1++ = '\0';
	return tmp;
}

int main()
{
	char str1[20] = "abcdef";
	char str2[] = "ghijkl";
	printf("%s\n", my_strncat(str1, str2, 10));
	return 0;
}
//模拟实现strncpy
char* my_strncpy(char* str1,const char* str2,size_t num)
{
	assert(str1&&str2);
	char* tmp = str1;
	while ((*str1++ = *str2++) && --num)
		;
	if (num)
		while (num--)
		{
			*str1++ = '\0';
		}
	return tmp;
}

int main()
{
	char str1[] = "abcdef";
	char str2[] = "ghijkl";
	printf("%s\n",my_strncpy(str1,str2,2));
	return 0;
}

int Check()
{
	int a = 0x01;
	return *(char*)&a;
}

int main()
{
	printf("%d\n", Check());
	return 0;
}
#endif