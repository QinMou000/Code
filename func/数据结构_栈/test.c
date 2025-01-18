#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"

void test()
{
	ST s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);
	STPush(&s, 4);
	STPop(&s);
	printf("%d\n", STTop(&s));
	printf("%d\n", STSize(&s));
	printf("%d\n",STEmpty(&s));
	
	while (!STEmpty(&s))
	{
		printf("%d ",s.data[s.top]);
		STPop(&s);
	}
	STDestroy(&s);
}


int main()
{
	test();
	return 0;
}