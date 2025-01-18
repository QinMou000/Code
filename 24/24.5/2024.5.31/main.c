#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char* s = malloc(sizeof(char)*1000);
	scanf("%s", s);
	printf("%s", s);
}
