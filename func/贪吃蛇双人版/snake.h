#pragma once
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<locale.h>
#include<stdbool.h>

#define POS_X1 24
#define POS_Y1 5
#define POS_X2 34
#define POS_Y2 9

#define WALL L'��'
#define BODY L'��'
#define FOOD L'��'
typedef struct SnakeNode
{
	//����
	int x;
	int y;
	//��һ���ڵ�
	struct SnakeNode* next;
}SnakeNode,*pSnakeNode;

enum DRECCTION//����
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//�ߵ�״̬
enum GAME_STATUS
{
	OK,//�����˳�
	KILL_BY_WALL,//ײǽ
	KILL_BY_SELF,//ײ�Լ�
	END_NORMAL,//�����˳�
	KILL_BY_OTHER//�����˵�ɱ
};

typedef struct Snake
{
	pSnakeNode _pSnake;//ָ����ͷ��ָ��
	pSnakeNode _pFood;//ָ��ʳ��ڵ��ָ��
	enum DRECCTION _dir;//�ߵķ���
	enum GAME_STAYUS _status;//��Ϸ״̬
	int _food_weight;//һ��ʳ�ﶼ����
	int _score;//�ܳɼ�
	int _sleep_time;//��Ϣʱ��

}Snake,*pSnake;
//����
void set_pos(short x, short y);//��λ���λ��

void Game_Start(pSnake ps1, pSnake ps2);//��ʼ��

void WelcomeToGame(void);//��ӡ��ӭ����

void CreateMap(void);//������ͼ

void InitSnake1(pSnake ps);//��ʼ������1

void InitSnake1(pSnake ps);//��ʼ������2

void CreateFood(pSnake ps1,pSnake ps2);//����ʳ��

void Game_Run(pSnake ps1, pSnake ps2);//��Ϸ�����߼�

void SnakeMove(pSnake ps1, pSnake ps2);//�ߵ��ƶ�

bool NextIsFood(pSnakeNode pn,pSnake ps);//�ж���һλ���Ƿ�Ϊʳ��

void EatFood(pSnakeNode pn, pSnake ps1,pSnake ps2);//�Ե�ʳ��

void NoFood(pSnakeNode pn, pSnake ps);//��һ��λ�ò���ʳ��

void KillByWall(pSnake ps);//���ײǽ

void KillBySelf(pSnake ps);//���ײ�Լ�

void Game_End(pSnake ps1, pSnake ps2);//��Ϸ�ƺ�

/*
�Ľ���
1.��ǽ
2.ʳ�����
3.���ʳ��
......
*/