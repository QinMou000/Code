#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<stdio.h>
#include<string>

//int main()
//{
//	FILE* pf = fopen("wq.txt","w");
//	assert(pf);
//	//бнбн
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}

#include<stdlib.h>
#include<string.h>

int cmp(char x, char y)
{
	return x - y;
}

int main()
{
	char* str = (char*)malloc(1024);
	gets(str);
	int len = strlen(str);
	qsort(str, len, sizeof(char), (int)cmp);
	printf("%c\n", str[0]);

	return 0;
}