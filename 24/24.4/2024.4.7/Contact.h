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


//通讯录的初始化
void ContactInit(Contact* con);
//通讯录的销毁
void ContactDesTroy(Contact* con);
//通讯录添加数据
void ContactAdd(Contact* con);
//通讯录删除数据
void ContactDel(Contact* con);
//通讯录的修改
void ContactModify(Contact* con);
//通讯录查找
void ContactFind(Contact* con);
//展示通讯录数据
void ContactShow(Contact* con);

