#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"
#include<stdio.h>
#include"Contact.h"

//void test1(void)
//{
//	SL s;
//	SLInit(&s);
//	SLPushBack(&s, 1);
//	SLPushBack(&s, 2);
//	SLPushBack(&s, 3);
//	SLPushBack(&s, 4);
//	SLPrint(s);
//
//	SLPushFront(&s, 4);
//	SLPrint(s);
//
//	SLPopBack(&s);
//	SLPopFront(&s);
//	SLPrint(s);
//
//	SLInsert(&s,2,3);
//	SLPrint(s);
//
//	SLErase(&s, 2);
//	SLPrint(s);
//
//}

void test2(void)
{
	Contact con;
	ContactInit(&con);
	ContactAdd(&con);
	ContactShow(&con);
	ContactModify(&con);
	ContactDel(&con);	
	ContactFind(&con);


}

int main()
{
	//test1();
	test2();
}