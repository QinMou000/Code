#define _CRT_SECURE_NO_WARNINGS
#include<stdbool.h>
#include<stdio.h>

int main()
{
	char a = 3;
	//00000011
	char b = 127;
	//01111111
	char c = a + b;
	//10000010
	//提升:11111111111111111111111110000010(补码)
	//源码:10000000000000000000000001111110
	//十进制:-126
	printf("%d\n",c);
	return 0;
}

#if 0
struct person
{
	char name[20];
	bool sex;
	char personal_num[18]; 
	int age;
	int high; 
	float weight;
}pe1,pe2,pe3;

int main()
{
	struct person pe1 = {.age=18,.high=172,.name="wangqin",.personal_num="500226200510302076",.sex=1,.weight=60.0f};
	printf("%d %d %s %s %d %.2f\n",pe1.age,pe1.high,pe1.name,pe1.personal_num,pe1.sex,pe1.weight);

	return 0;
}
#endif