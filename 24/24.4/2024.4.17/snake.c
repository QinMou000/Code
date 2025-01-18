#define _CRT_SECURE_NO_WARNINGS 1

#include"snake.h"


void set_pos(short x, short y)
{
	//获得标准输出设备的句柄
	HANDLE houtput = NULL; 
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//定位光标的位置
	COORD pos = { x,y };
	SetConsoleCursorPosition(houtput,pos);
}
void WelcomeToGame()
{
	set_pos(40, 12);
	wprintf(L"欢迎来到贪吃蛇小游戏");
	set_pos(42,18);
	system("pause");
	system("cls");
	set_pos(30, 12);
	wprintf(L"用上下左右控制蛇的移动，按 {[ 加速, ]} 减速\n");
	set_pos(38, 13);
	wprintf(L"加速可以得到更高的分数\n");
	set_pos(42, 18);
	system("pause");
	system("cls");
}

void CreateMap()
{
	//上
	int i = 0;
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}
	//下
	set_pos(0,25);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}
	//左
	for (i = 1; i < 25; i++)
	{
		set_pos(0, i);
		wprintf(L"%lc", WALL);
	}
	//右
	for (i = 1; i < 25; i++)
	{
		set_pos(56, i);
		wprintf(L"%lc", WALL);
	}
}

void InitSnake(pSnake ps)
{
	int i = 0;
	pSnakeNode cur = NULL;
	for (int i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc()");
			return;
		}
		cur->next = NULL;
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;
		//头插插入
		if (ps->_pSnake == NULL)
			ps->_pSnake = cur;
		else
		{
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}
	cur = ps->_pSnake;
	while (cur)
	{
		set_pos(cur->x,cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//设置蛇的属性
	ps->_dir = RIGHT;//默认
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;//单位为ms
	ps->_status = OK;
}

void CreateFood(pSnake ps)//创建食物
{
	int x = 0;
	int y = 0;
again:
	do
	{
		x = rand() % 52 + 2;//2~54
		y = rand() % 24 + 1;//1~25
	} while (x % 2 != 0);//x为2的倍数
	//不能和蛇身的坐标相同
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
			goto again;
		cur = cur->next;
	}
	//创建食物节点
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood()::malloc");
		return;
	}
	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;
	set_pos(x, y);
	wprintf(L"%lc", FOOD);
	ps->_pFood = pFood;
}

void Game_Start(pSnake ps)//初始化
{
	//0.设置窗口大小/名字
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");

	//1.隐藏光标
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput,&CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(houtput,&CursorInfo);
	
	//2.打印欢迎界面,介绍功能
	WelcomeToGame();

	//3.绘制地图
	CreateMap();

	//4.创建蛇
	InitSnake(ps);

	//5.创建食物
	CreateFood(ps);
}

void PrintHelpInfo()
{
	set_pos(64, 10);
	wprintf(L"%ls",L"不能穿墙，不能撞到自己");
	set_pos(64, 11);
	wprintf(L"%ls", L"用上下左右控制蛇的移动");
	set_pos(64, 12);
	wprintf(L"%ls", L"按 {[ 键加速, ]} 键减速");
	set_pos(64, 13);
	wprintf(L"%ls", L"ESC:退出游戏，space：暂停游戏");
	set_pos(66, 16);
	wprintf(L"%ls", L"/.钦某/.版权/.");
}

#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&1)?1:0)

void Pause()
{
	while (1)
	{	
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
			break;
	}
}

bool NextIsFood(pSnakeNode pn, pSnake ps)//判断下一位置是否为食物
{
	return (ps->_pFood->x == pn->x && ps->_pFood->y == pn->y);
}

void EatFood(pSnakeNode pn, pSnake ps)
{
	//头插
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;

	//释放下一个位置的节点
	free(pn);
	pn = NULL;

	//打印
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		set_pos(cur->x, cur->y);
		wprintf(L"%lc",BODY);
		cur = cur->next;
	}
	ps->_score += ps->_food_weight;
	//重新创建食物
	CreateFood(ps);
}

void NoFood(pSnakeNode pn, pSnake ps)//下一个位置不是食物
{
	//头插
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;

	pSnakeNode cur = ps->_pSnake;
	while (cur->next->next)
	{
		set_pos(cur->x,cur->y);
		wprintf(L"%lc",BODY);

		cur = cur->next;
	}
	//把最后一个节点打印空格
	set_pos(cur->next->x,cur->next->y);
	printf("  ");
	//将最后一个节点释放
	free(cur->next);
	//将倒数第二个节点置为空
	cur->next = NULL;
}

void KillByWall(pSnake ps)//检测撞墙
{
	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 ||
		ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
	{
		ps->_status = KILL_BY_WALL;
	}
}

void KillBySelf(pSnake ps)//检测撞自己
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur)
	{
		if (cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y)
		{
			ps->_status = KILL_BY_SELF;
			break;
		}
		cur = cur->next;
	}
}

void SnakeMove(pSnake ps)//蛇的移动
{
	//创建蛇头的下一个节点
	pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNextNode == NULL)
	{
		perror("SnakeMove()::malloc()");
		return;
	}
	switch (ps->_dir)
	{
	case UP:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y-1;
		break;
	case DOWN:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y + 1;
		break;
	case LEFT:
		pNextNode->x = ps->_pSnake->x - 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	case RIGHT:
		pNextNode->x = ps->_pSnake->x + 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	}
	if (NextIsFood(pNextNode,ps))//检测下一个位置是否为食物
	{
		EatFood(pNextNode, ps);
	}
	else
	{
		NoFood(pNextNode, ps);
	}
	//检测是否撞墙
	KillByWall(ps);
	//检测是否撞自己
	KillBySelf(ps);
}

void Game_Run(pSnake ps)//游戏运行逻辑
{
	//打印帮助信息
	PrintHelpInfo();
	do
	{
		//打印分数，食物权重
		set_pos(64, 8);
		printf("总分数:%d\n",ps->_score);
		set_pos(64, 9);
		printf("当前食物权重:%2d\n", ps->_food_weight);
		//按键检测
		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)
		{
			ps->_dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP)
		{
			ps->_dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)
		{
			ps->_dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)
		{
			ps->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			//暂停
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//正常退出
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_OEM_6))
		{
			//加速
			if (ps->_sleep_time > 80)
			{
				ps->_sleep_time -= 30;
				ps->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(VK_OEM_4))
		{
			//减速
			if (ps->_food_weight > 2)
			{
				ps->_sleep_time += 30;
				ps->_food_weight -= 2;
			}
		}

		SnakeMove(ps);//蛇走一步的过程
		Sleep(ps->_sleep_time);

	} while (ps->_status == OK);
}

void Game_End(pSnake ps)//游戏善后
{
	set_pos(24,12);
	switch (ps->_status)
	{
	case END_NORMAL:
		printf("您主动结束游戏\n");
		break;
	case KILL_BY_WALL:
		printf("您被墙单杀了\n");
		break;
	case KILL_BY_SELF:
		printf("您被自己单杀了\n");
		break;
	}

	//释放蛇身链表
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}