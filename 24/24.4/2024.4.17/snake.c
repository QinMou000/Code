#define _CRT_SECURE_NO_WARNINGS 1

#include"snake.h"


void set_pos(short x, short y)
{
	//��ñ�׼����豸�ľ��
	HANDLE houtput = NULL; 
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//��λ����λ��
	COORD pos = { x,y };
	SetConsoleCursorPosition(houtput,pos);
}
void WelcomeToGame()
{
	set_pos(40, 12);
	wprintf(L"��ӭ����̰����С��Ϸ");
	set_pos(42,18);
	system("pause");
	system("cls");
	set_pos(30, 12);
	wprintf(L"���������ҿ����ߵ��ƶ����� {[ ����, ]} ����\n");
	set_pos(38, 13);
	wprintf(L"���ٿ��Եõ����ߵķ���\n");
	set_pos(42, 18);
	system("pause");
	system("cls");
}

void CreateMap()
{
	//��
	int i = 0;
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}
	//��
	set_pos(0,25);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}
	//��
	for (i = 1; i < 25; i++)
	{
		set_pos(0, i);
		wprintf(L"%lc", WALL);
	}
	//��
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
		//ͷ�����
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
	//�����ߵ�����
	ps->_dir = RIGHT;//Ĭ��
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;//��λΪms
	ps->_status = OK;
}

void CreateFood(pSnake ps)//����ʳ��
{
	int x = 0;
	int y = 0;
again:
	do
	{
		x = rand() % 52 + 2;//2~54
		y = rand() % 24 + 1;//1~25
	} while (x % 2 != 0);//xΪ2�ı���
	//���ܺ������������ͬ
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
			goto again;
		cur = cur->next;
	}
	//����ʳ��ڵ�
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

void Game_Start(pSnake ps)//��ʼ��
{
	//0.���ô��ڴ�С/����
	system("mode con cols=100 lines=30");
	system("title ̰����");

	//1.���ع��
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput,&CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(houtput,&CursorInfo);
	
	//2.��ӡ��ӭ����,���ܹ���
	WelcomeToGame();

	//3.���Ƶ�ͼ
	CreateMap();

	//4.������
	InitSnake(ps);

	//5.����ʳ��
	CreateFood(ps);
}

void PrintHelpInfo()
{
	set_pos(64, 10);
	wprintf(L"%ls",L"���ܴ�ǽ������ײ���Լ�");
	set_pos(64, 11);
	wprintf(L"%ls", L"���������ҿ����ߵ��ƶ�");
	set_pos(64, 12);
	wprintf(L"%ls", L"�� {[ ������, ]} ������");
	set_pos(64, 13);
	wprintf(L"%ls", L"ESC:�˳���Ϸ��space����ͣ��Ϸ");
	set_pos(66, 16);
	wprintf(L"%ls", L"/.��ĳ/.��Ȩ/.");
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

bool NextIsFood(pSnakeNode pn, pSnake ps)//�ж���һλ���Ƿ�Ϊʳ��
{
	return (ps->_pFood->x == pn->x && ps->_pFood->y == pn->y);
}

void EatFood(pSnakeNode pn, pSnake ps)
{
	//ͷ��
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;

	//�ͷ���һ��λ�õĽڵ�
	free(pn);
	pn = NULL;

	//��ӡ
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		set_pos(cur->x, cur->y);
		wprintf(L"%lc",BODY);
		cur = cur->next;
	}
	ps->_score += ps->_food_weight;
	//���´���ʳ��
	CreateFood(ps);
}

void NoFood(pSnakeNode pn, pSnake ps)//��һ��λ�ò���ʳ��
{
	//ͷ��
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;

	pSnakeNode cur = ps->_pSnake;
	while (cur->next->next)
	{
		set_pos(cur->x,cur->y);
		wprintf(L"%lc",BODY);

		cur = cur->next;
	}
	//�����һ���ڵ��ӡ�ո�
	set_pos(cur->next->x,cur->next->y);
	printf("  ");
	//�����һ���ڵ��ͷ�
	free(cur->next);
	//�������ڶ����ڵ���Ϊ��
	cur->next = NULL;
}

void KillByWall(pSnake ps)//���ײǽ
{
	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 56 ||
		ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
	{
		ps->_status = KILL_BY_WALL;
	}
}

void KillBySelf(pSnake ps)//���ײ�Լ�
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

void SnakeMove(pSnake ps)//�ߵ��ƶ�
{
	//������ͷ����һ���ڵ�
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
	if (NextIsFood(pNextNode,ps))//�����һ��λ���Ƿ�Ϊʳ��
	{
		EatFood(pNextNode, ps);
	}
	else
	{
		NoFood(pNextNode, ps);
	}
	//����Ƿ�ײǽ
	KillByWall(ps);
	//����Ƿ�ײ�Լ�
	KillBySelf(ps);
}

void Game_Run(pSnake ps)//��Ϸ�����߼�
{
	//��ӡ������Ϣ
	PrintHelpInfo();
	do
	{
		//��ӡ������ʳ��Ȩ��
		set_pos(64, 8);
		printf("�ܷ���:%d\n",ps->_score);
		set_pos(64, 9);
		printf("��ǰʳ��Ȩ��:%2d\n", ps->_food_weight);
		//�������
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
			//��ͣ
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//�����˳�
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_OEM_6))
		{
			//����
			if (ps->_sleep_time > 80)
			{
				ps->_sleep_time -= 30;
				ps->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(VK_OEM_4))
		{
			//����
			if (ps->_food_weight > 2)
			{
				ps->_sleep_time += 30;
				ps->_food_weight -= 2;
			}
		}

		SnakeMove(ps);//����һ���Ĺ���
		Sleep(ps->_sleep_time);

	} while (ps->_status == OK);
}

void Game_End(pSnake ps)//��Ϸ�ƺ�
{
	set_pos(24,12);
	switch (ps->_status)
	{
	case END_NORMAL:
		printf("������������Ϸ\n");
		break;
	case KILL_BY_WALL:
		printf("����ǽ��ɱ��\n");
		break;
	case KILL_BY_SELF:
		printf("�����Լ���ɱ��\n");
		break;
	}

	//�ͷ���������
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}