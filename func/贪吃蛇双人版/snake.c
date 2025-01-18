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
	set_pos(34, 11);
	wprintf(L"一号玩家用WSAD控制蛇的移动\n");
	set_pos(32, 12);
	wprintf(L"二号玩家用上下左右控制蛇的移动\n");
	set_pos(40, 13);
	wprintf(L"[{加速，]}减速");
	set_pos(36, 14);
	wprintf(L"加速可以得到更高的分数\n");
	set_pos(40, 18);
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

void InitSnake1(pSnake ps1)
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
		cur->x = POS_X1 + 2 * i;
		cur->y = POS_Y1;
		//头插插入
		if (ps1->_pSnake == NULL)
			ps1->_pSnake = cur;
		else
		{
			cur->next = ps1->_pSnake;
			ps1->_pSnake = cur;
		}
	}
	cur = ps1->_pSnake;
	while (cur)
	{
		set_pos(cur->x,cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//设置蛇的属性
	ps1->_dir = RIGHT;//默认
	ps1->_score = 0;
	ps1->_food_weight = 10;
	ps1->_sleep_time = 200;//单位为ms
	ps1->_status = OK;
}
void InitSnake2(pSnake ps2)
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
		cur->x = POS_X2 - 2 * i;
		cur->y = POS_Y2;
		//头插插入
		if (ps2->_pSnake == NULL)
			ps2->_pSnake = cur;
		else
		{
			cur->next = ps2->_pSnake;
			ps2->_pSnake = cur;
		}
	}
	cur = ps2->_pSnake;
	while (cur)
	{
		set_pos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//设置蛇的属性
	ps2->_dir = LEFT;//默认
	ps2->_score = 0;
	ps2->_food_weight = 10;
	ps2->_sleep_time = 200;//单位为ms
	ps2->_status = OK;
}

void CreateFood(pSnake ps1,pSnake ps2)//创建食物
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
	pSnakeNode cur1 = ps1->_pSnake;
	while (cur1)
	{
		if (x == cur1->x && y == cur1->y)
			goto again;
		cur1 = cur1->next;
	}
	pSnakeNode cur2 = ps2->_pSnake;
	while (cur2)
	{
		if (x == cur2->x && y == cur2->y)
			goto again;
		cur2 = cur2->next;
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
	ps1->_pFood = pFood;
	ps2->_pFood = pFood;
}

void Game_Start(pSnake ps1, pSnake ps2)//初始化
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
	InitSnake1(ps1);
	InitSnake2(ps2);

	//5.创建食物
	CreateFood(ps1,ps2);
}

void PrintHelpInfo()
{
	set_pos(64, 10);
	wprintf(L"%ls",L"不能穿墙，不能撞到自己");
	set_pos(64, 11);
	wprintf(L"%ls", L"一号玩家用WSAD控制蛇1的移动");
	set_pos(64, 12);
	wprintf(L"%ls", L"二号玩家用上下左右控制蛇的移动");
	set_pos(64, 13);
	wprintf(L"%ls", L"按 {[ 键加速, ]} 键减速");
	set_pos(64, 14);
	wprintf(L"%ls", L"ESC:退出游戏，space：暂停游戏");
	set_pos(64, 15);
	wprintf(L"%ls", L"最终活下来的那条蛇为胜者");
	set_pos(66, 18);
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

void EatFood(pSnakeNode pn, pSnake ps1,pSnake ps2)
{
	//头插
	ps1->_pFood->next = ps1->_pSnake;
	ps1->_pSnake = ps1->_pFood;

	//释放下一个位置的节点
	free(pn);
	pn = NULL;

	//打印
	pSnakeNode cur = ps1->_pSnake;
	while (cur)
	{
		set_pos(cur->x, cur->y);
		wprintf(L"%lc",BODY);
		cur = cur->next;
	}
	ps1->_score += ps1->_food_weight;
	//重新创建食物
	CreateFood(ps1,ps2);
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
		ps->_pSnake->y == 0 || ps->_pSnake->y == 25)
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

void KillByOther(pSnake ps1,pSnake ps2)
{
	pSnakeNode cur = ps2->_pSnake->next;
	while (cur)
	{
		if (cur->x == ps1->_pSnake->x && cur->y == ps1->_pSnake->y)
		{
			ps1->_status = KILL_BY_OTHER;
			break;
		}
		cur = cur->next;
	}
}

void Head_Head(pSnake ps1, pSnake ps2)
{
	if (ps1->_pSnake->x == ps2->_pSnake->x && ps1->_pSnake->y == ps2->_pSnake->y)
	{
		set_pos(18, 15);
		printf("<<平局>>");
		exit(1);
		set_pos(0, 25);
	}
}

void SnakeMove(pSnake ps1,pSnake ps2)//蛇的移动
{
	//创建蛇头的下一个节点
	pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNextNode == NULL)
	{
		perror("SnakeMove()::malloc()");
		return;
	}
	switch (ps1->_dir)
	{
	case UP:
		pNextNode->x = ps1->_pSnake->x;
		pNextNode->y = ps1->_pSnake->y-1;
		break;
	case DOWN:
		pNextNode->x = ps1->_pSnake->x;
		pNextNode->y = ps1->_pSnake->y + 1;
		break;
	case LEFT:
		pNextNode->x = ps1->_pSnake->x - 2;
		pNextNode->y = ps1->_pSnake->y;
		break;
	case RIGHT:
		pNextNode->x = ps1->_pSnake->x + 2;
		pNextNode->y = ps1->_pSnake->y;
		break;
	}
	if (NextIsFood(pNextNode,ps1))//检测下一个位置是否为食物
	{
		EatFood(pNextNode, ps1, ps2);
	}
	else
	{
		NoFood(pNextNode, ps1);
	}
	//检测是否撞墙
	KillByWall(ps1);
	//检测是否撞自己
	KillBySelf(ps1);
	//检测是否被别人撞
	KillByOther(ps1, ps2);
	KillByOther(ps2, ps1);
	//检测头碰头
	Head_Head(ps1, ps2);
	Head_Head(ps2, ps1);
}

void Game_Run(pSnake ps1, pSnake ps2)//游戏运行逻辑
{
	//打印帮助信息
	PrintHelpInfo();
	do
	{
		//打印分数，食物权重
		set_pos(0, 26);
		printf("一号玩家的总分数:%d\n", ps2->_score);
		set_pos(30, 26);
		printf("二号玩家的总分数:%d\n",ps1->_score);
		set_pos(64, 9);
		printf("当前食物权重:%2d\n", ps1->_food_weight);
		//按键检测
		if (KEY_PRESS(0x26) && ps1->_dir != DOWN)
		{
			ps1->_dir = UP;
		}
		else if (KEY_PRESS(0x28) && ps1->_dir != UP)
		{
			ps1->_dir = DOWN;
		}
		else if (KEY_PRESS(0x25) && ps1->_dir != RIGHT)
		{
			ps1->_dir = LEFT;
		}
		else if (KEY_PRESS(0x27) && ps1->_dir != LEFT)
		{
			ps1->_dir = RIGHT;
		}
		if (KEY_PRESS(0x57) && ps2->_dir != DOWN)//W键
		{
			ps2->_dir = UP;
		}
		else if (KEY_PRESS(0x53) && ps2->_dir != UP)//S键
		{
			ps2->_dir = DOWN;
		}
		else if (KEY_PRESS(0x41) && ps2->_dir != RIGHT)//A键
		{
			ps2->_dir = LEFT;
		}
		else if (KEY_PRESS(0x44) && ps2->_dir != LEFT)//D键
		{
			ps2->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			//暂停
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//正常退出
			ps1->_status = END_NORMAL;
			ps2->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_OEM_6))
		{
			//加速
			if (ps1->_sleep_time > 80)
			{
				ps1->_sleep_time -= 30;
				ps1->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(VK_OEM_4))
		{
			//减速
			if (ps1->_food_weight > 2)
			{
				ps1->_sleep_time += 30;
				ps1->_food_weight -= 2;
			}
		}

		SnakeMove(ps1,ps2);//蛇走一步的过程
		SnakeMove(ps2,ps1);//蛇走一步的过程

		Sleep(ps1->_sleep_time);

	} while (ps1->_status == OK && ps2->_status == OK);
}

void Game_End(pSnake ps1, pSnake ps2)//游戏善后
{

	//if (ps1->_status == OK)
	//{
	//	switch (ps2->_status)
	//	{
	//	case KILL_BY_SELF:
	//		wprintf(L"一号玩家被自己单杀，二号玩家获胜！");
	//		break;
	//	case KILL_BY_WALL:
	//		wprintf(L"一号玩家被墙单杀，二号玩家获胜！");
	//		break;
	//	case KILL_BY_OTHER:
	//		wprintf(L"一号玩家被二号玩家单杀，二号玩家获胜！");
	//		break;
	//	}
	//}
	//if (ps2->_status == OK)
	//{
	//	switch (ps1->_status)
	//	{
	//	case KILL_BY_SELF:
	//		wprintf(L"二号玩家被自己单杀，一号玩家获胜！");
	//		break;
	//	case KILL_BY_WALL:
	//		wprintf(L"二号玩家被墙单杀，一号玩家获胜！");
	//		break;
	//	case KILL_BY_OTHER:
	//		wprintf(L"二号玩家被一号玩家单杀，一号玩家获胜！");
	//		break;
	//	}
	//}
	//if (ps1->_status == END_NORMAL && ps2->_status == END_NORMAL)
	//	wprintf(L"难分高下，要不再来一局？");

	system("cls");
	set_pos(42,12);
	if (ps1->_score > ps2->_score)
		printf("二号玩家获胜！");
	else if (ps1->_score < ps2->_score)
		printf("一号玩家获胜！");
	else
		printf("《平局》");

	//释放蛇身链表
	pSnakeNode cur1 = ps1->_pSnake;
	while (cur1)
	{
		pSnakeNode del = cur1;
		cur1 = cur1->next;
		free(del);
	}
	pSnakeNode cur2 = ps2->_pSnake;
	while (cur2)
	{
		pSnakeNode del = cur2;
		cur2 = cur2->next;
		free(del);
	}
}