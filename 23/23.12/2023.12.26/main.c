#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 10;

	printf("%d\n",a);

	int * pa = &a;

	*pa = 2023;

	printf("%d\n",a);

	printf("%zd\n",sizeof(int*));
	printf("%zd\n", sizeof(char*));
	printf("%zd\n", sizeof(long*));
	printf("%zd\n", sizeof(float*));
	printf("%zd\n", sizeof(short*));
	printf("%zd\n", sizeof(double*));

	printf("%p",&a);


	return 0;


}