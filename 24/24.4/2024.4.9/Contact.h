#pragma once

#define NAME_MAX 20
//ǰ������
typedef struct SList_Node contact;
//�û�����
typedef struct PersonInfo
{
    char name[NAME_MAX];
    char tel[11];
}PeoInfo;

//��ʼ��ͨѶ¼
void InitContact(contact** con);
//���ͨѶ¼����
void AddContact(contact** con);
//ɾ��ͨѶ¼����
void DelContact(contact** con);
//չʾͨѶ¼����
void ShowContact(contact* con);
//����ͨѶ¼����
contact* FindContact(contact* con, char* find);
//�޸�ͨѶ¼����
void ModifyContact(contact** con);
//����ͨѶ¼����
void DestroyContact(contact** con);