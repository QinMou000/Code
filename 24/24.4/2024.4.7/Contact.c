#define _CRT_SECURE_NO_WARNINGS 1

#include"Contact.h"
#include"SeqList.h"
#include<string.h>

void ContactInit(Contact* con)
{
	SLInit(con);
}

void ContactDesTroy(Contact* con)
{
	void SLDestroy(con);
}

void ContactAdd(Contact* con)
{
	PF info;
	printf("请输入姓名：");
	scanf("%s", info.name);
	printf("请输入电话号码：");
	scanf("%s", info.tel);
	SLPushBack(con, info);
}

int FindbyName(Contact* con, char* name)
{
	for (int i = 0; i < con->size; i++)
		if (0 == strcmp(con->Data[i].name, name))
		{
			return i;
		}
	return -1;
}

void ContactDel(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要删除的人的名字：");
	scanf("%s",name);
	int find = FindbyName(con, name);
	if (find < 0)
	{
		printf("查无此人");
		return;
	}
	void SLErase(con, find);
	printf("删除成功！\n");
}

void ContactShow(Contact* con)
{
	int i = 0;
	for (i = 0; i < con->size; i++)
	{
		printf("\n第%d位：", i);
		printf("姓名：%s ", con->Data[i].name);
		printf("电话：%s\n", con->Data[i].tel);
	}
}

void ContactModify(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要修改的人的名字：");
	scanf("%s",name);
	int find = FindbyName(con, name);
	if (find < 0)
	{
		printf("您输入的人不存在！");
		return;
	}
	printf("请重新输入名字：");
	scanf("%s",con->Data[find].name);
	printf("请重新输入电话：");
	scanf("%s", con->Data[find].tel);
	printf("信息修改成功！\n");
}

void ContactFind(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要查找的人的名字：");
	scanf("%s", name);
	int find = FindbyName(con, name);
	if (find < 0)
	{
		printf("您要查找的人不存在！");
		return;
	}
	printf("姓名：%s\n",con->Data[find].name);
	printf("电话：%s\n", con->Data[find].tel);

}

