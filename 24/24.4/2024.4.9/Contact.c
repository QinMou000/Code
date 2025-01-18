#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include"SList.h"
#include<stdio.h>
#include<string.h>
//初始化通讯录
void InitContact(contact** con)
{
	contact* phead = NULL;
	*con = phead;
}
//添加通讯录数据
void AddContact(contact** con)
{
	PeoInfo newperson;
	printf("姓名：");
	scanf("%s", newperson.name);
	printf("电话：");
	scanf("%s",newperson.tel);
	SLTPushBack(con,newperson);
}
//删除通讯录数据
void DelContact(contact** con)
{
	char del[NAME_MAX];
	printf("要删除的联系人的姓名：");
	scanf("%s",del);
	
	contact* find = FindContact(*con, del);
	
	if (find == NULL)
	{
		printf("要删除的联系人不存在");
		return;
	}
	
	SLTErase(con, find);
}
//展示通讯录数据
void ShowContact(contact* con)
{
	assert(con);
	while (con)
	{
		printf("姓名：%s\n", con->Data.name);
		printf("电话：%s\n", con->Data.tel);
		con = con->Next;
	}
}
//查找通讯录数据
contact* FindContact(contact* con,char* find)
{
	contact* pcur = con;
	while (pcur)
	{
		if (strcmp(find, pcur->Data.name) == 0)
		{
			return pcur;
		}
		pcur = pcur->Next;
	}
	return NULL;
}
//修改通讯录数据
void ModifyContact(contact** con)
{
	printf("请输入要修改联系人的名字：");
	char mod[NAME_MAX];
	scanf("%s",mod);
	contact* find = FindContact(*con, mod);
	if (find == NULL)
	{
		printf("要修改的联系人不存在！");
		return;
	}
	PeoInfo newperson;
	printf("请输入修改后的名字、电话：");
	scanf("%s%s",newperson.name,newperson.tel);
	SLTInsertAfter(find,newperson);
	SLTErase(con,find);
}
//销毁通讯录数据
void DestroyContact(contact** con)
{
	SListDesTroy(con);
}