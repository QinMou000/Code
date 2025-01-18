#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include"SList.h"
#include<stdio.h>
#include<string.h>
//��ʼ��ͨѶ¼
void InitContact(contact** con)
{
	contact* phead = NULL;
	*con = phead;
}
//���ͨѶ¼����
void AddContact(contact** con)
{
	PeoInfo newperson;
	printf("������");
	scanf("%s", newperson.name);
	printf("�绰��");
	scanf("%s",newperson.tel);
	SLTPushBack(con,newperson);
}
//ɾ��ͨѶ¼����
void DelContact(contact** con)
{
	char del[NAME_MAX];
	printf("Ҫɾ������ϵ�˵�������");
	scanf("%s",del);
	
	contact* find = FindContact(*con, del);
	
	if (find == NULL)
	{
		printf("Ҫɾ������ϵ�˲�����");
		return;
	}
	
	SLTErase(con, find);
}
//չʾͨѶ¼����
void ShowContact(contact* con)
{
	assert(con);
	while (con)
	{
		printf("������%s\n", con->Data.name);
		printf("�绰��%s\n", con->Data.tel);
		con = con->Next;
	}
}
//����ͨѶ¼����
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
//�޸�ͨѶ¼����
void ModifyContact(contact** con)
{
	printf("������Ҫ�޸���ϵ�˵����֣�");
	char mod[NAME_MAX];
	scanf("%s",mod);
	contact* find = FindContact(*con, mod);
	if (find == NULL)
	{
		printf("Ҫ�޸ĵ���ϵ�˲����ڣ�");
		return;
	}
	PeoInfo newperson;
	printf("�������޸ĺ�����֡��绰��");
	scanf("%s%s",newperson.name,newperson.tel);
	SLTInsertAfter(find,newperson);
	SLTErase(con,find);
}
//����ͨѶ¼����
void DestroyContact(contact** con)
{
	SListDesTroy(con);
}