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
	printf("������������");
	scanf("%s", info.name);
	printf("������绰���룺");
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
	printf("������Ҫɾ�����˵����֣�");
	scanf("%s",name);
	int find = FindbyName(con, name);
	if (find < 0)
	{
		printf("���޴���");
		return;
	}
	void SLErase(con, find);
	printf("ɾ���ɹ���\n");
}

void ContactShow(Contact* con)
{
	int i = 0;
	for (i = 0; i < con->size; i++)
	{
		printf("\n��%dλ��", i);
		printf("������%s ", con->Data[i].name);
		printf("�绰��%s\n", con->Data[i].tel);
	}
}

void ContactModify(Contact* con)
{
	char name[NAME_MAX];
	printf("������Ҫ�޸ĵ��˵����֣�");
	scanf("%s",name);
	int find = FindbyName(con, name);
	if (find < 0)
	{
		printf("��������˲����ڣ�");
		return;
	}
	printf("�������������֣�");
	scanf("%s",con->Data[find].name);
	printf("����������绰��");
	scanf("%s", con->Data[find].tel);
	printf("��Ϣ�޸ĳɹ���\n");
}

void ContactFind(Contact* con)
{
	char name[NAME_MAX];
	printf("������Ҫ���ҵ��˵����֣�");
	scanf("%s", name);
	int find = FindbyName(con, name);
	if (find < 0)
	{
		printf("��Ҫ���ҵ��˲����ڣ�");
		return;
	}
	printf("������%s\n",con->Data[find].name);
	printf("�绰��%s\n", con->Data[find].tel);

}

