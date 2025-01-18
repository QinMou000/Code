#pragma once

#define NAME_MAX 20
//前置声明
typedef struct SList_Node contact;
//用户数据
typedef struct PersonInfo
{
    char name[NAME_MAX];
    char tel[11];
}PeoInfo;

//初始化通讯录
void InitContact(contact** con);
//添加通讯录数据
void AddContact(contact** con);
//删除通讯录数据
void DelContact(contact** con);
//展示通讯录数据
void ShowContact(contact* con);
//查找通讯录数据
contact* FindContact(contact* con, char* find);
//修改通讯录数据
void ModifyContact(contact** con);
//销毁通讯录数据
void DestroyContact(contact** con);