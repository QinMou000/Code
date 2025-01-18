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

#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'
typedef struct SnakeNode
{
	//坐标
	int x;
	int y;
	//下一个节点
	struct SnakeNode* next;
}SnakeNode,*pSnakeNode;

enum DRECCTION//方向
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

//蛇的状态
enum GAME_STATUS
{
	OK,//正常退出
	KILL_BY_WALL,//撞墙
	KILL_BY_SELF,//撞自己
	END_NORMAL,//正常退出
	KILL_BY_OTHER//被别人单杀
};

typedef struct Snake
{
	pSnakeNode _pSnake;//指向蛇头的指针
	pSnakeNode _pFood;//指向食物节点的指针
	enum DRECCTION _dir;//蛇的方向
	enum GAME_STAYUS _status;//游戏状态
	int _food_weight;//一个食物都分数
	int _score;//总成绩
	int _sleep_time;//休息时间

}Snake,*pSnake;
//声明
void set_pos(short x, short y);//定位光标位置

void Game_Start(pSnake ps1, pSnake ps2);//初始化

void WelcomeToGame(void);//打印欢迎界面

void CreateMap(void);//创建地图

void InitSnake1(pSnake ps);//初始化蛇身1

void InitSnake1(pSnake ps);//初始化蛇身2

void CreateFood(pSnake ps1,pSnake ps2);//创建食物

void Game_Run(pSnake ps1, pSnake ps2);//游戏运行逻辑

void SnakeMove(pSnake ps1, pSnake ps2);//蛇的移动

bool NextIsFood(pSnakeNode pn,pSnake ps);//判断下一位置是否为食物

void EatFood(pSnakeNode pn, pSnake ps1,pSnake ps2);//吃掉食物

void NoFood(pSnakeNode pn, pSnake ps);//下一个位置不是食物

void KillByWall(pSnake ps);//检测撞墙

void KillBySelf(pSnake ps);//检测撞自己

void Game_End(pSnake ps1, pSnake ps2);//游戏善后

/*
改进：
1.穿墙
2.食物分类
3.多个食物
......
*/