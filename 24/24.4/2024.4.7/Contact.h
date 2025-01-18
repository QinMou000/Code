#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define NAME_MAX 20
#define TEL_MAX 11

typedef struct personinfo
{
	char name[NAME_MAX];
	char tel[TEL_MAX];
}PF;

typedef struct SeqList Contact;


//ͨѶ¼�ĳ�ʼ��
void ContactInit(Contact* con);
//ͨѶ¼������
void ContactDesTroy(Contact* con);
//ͨѶ¼�������
void ContactAdd(Contact* con);
//ͨѶ¼ɾ������
void ContactDel(Contact* con);
//ͨѶ¼���޸�
void ContactModify(Contact* con);
//ͨѶ¼����
void ContactFind(Contact* con);
//չʾͨѶ¼����
void ContactShow(Contact* con);

