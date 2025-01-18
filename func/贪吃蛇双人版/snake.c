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
	set_pos(34, 11);
	wprintf(L"һ�������WSAD�����ߵ��ƶ�\n");
	set_pos(32, 12);
	wprintf(L"����������������ҿ����ߵ��ƶ�\n");
	set_pos(40, 13);
	wprintf(L"[{���٣�]}����");
	set_pos(36, 14);
	wprintf(L"���ٿ��Եõ����ߵķ���\n");
	set_pos(40, 18);
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
		//ͷ�����
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
	//�����ߵ�����
	ps1->_dir = RIGHT;//Ĭ��
	ps1->_score = 0;
	ps1->_food_weight = 10;
	ps1->_sleep_time = 200;//��λΪms
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
		//ͷ�����
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
	//�����ߵ�����
	ps2->_dir = LEFT;//Ĭ��
	ps2->_score = 0;
	ps2->_food_weight = 10;
	ps2->_sleep_time = 200;//��λΪms
	ps2->_status = OK;
}

void CreateFood(pSnake ps1,pSnake ps2)//����ʳ��
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
	ps1->_pFood = pFood;
	ps2->_pFood = pFood;
}

void Game_Start(pSnake ps1, pSnake ps2)//��ʼ��
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
	InitSnake1(ps1);
	InitSnake2(ps2);

	//5.����ʳ��
	CreateFood(ps1,ps2);
}

void PrintHelpInfo()
{
	set_pos(64, 10);
	wprintf(L"%ls",L"���ܴ�ǽ������ײ���Լ�");
	set_pos(64, 11);
	wprintf(L"%ls", L"һ�������WSAD������1���ƶ�");
	set_pos(64, 12);
	wprintf(L"%ls", L"����������������ҿ����ߵ��ƶ�");
	set_pos(64, 13);
	wprintf(L"%ls", L"�� {[ ������, ]} ������");
	set_pos(64, 14);
	wprintf(L"%ls", L"ESC:�˳���Ϸ��space����ͣ��Ϸ");
	set_pos(64, 15);
	wprintf(L"%ls", L"���ջ�������������Ϊʤ��");
	set_pos(66, 18);
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

void EatFood(pSnakeNode pn, pSnake ps1,pSnake ps2)
{
	//ͷ��
	ps1->_pFood->next = ps1->_pSnake;
	ps1->_pSnake = ps1->_pFood;

	//�ͷ���һ��λ�õĽڵ�
	free(pn);
	pn = NULL;

	//��ӡ
	pSnakeNode cur = ps1->_pSnake;
	while (cur)
	{
		set_pos(cur->x, cur->y);
		wprintf(L"%lc",BODY);
		cur = cur->next;
	}
	ps1->_score += ps1->_food_weight;
	//���´���ʳ��
	CreateFood(ps1,ps2);
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
		ps->_pSnake->y == 0 || ps->_pSnake->y == 25)
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
		printf("<<ƽ��>>");
		exit(1);
		set_pos(0, 25);
	}
}

void SnakeMove(pSnake ps1,pSnake ps2)//�ߵ��ƶ�
{
	//������ͷ����һ���ڵ�
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
	if (NextIsFood(pNextNode,ps1))//�����һ��λ���Ƿ�Ϊʳ��
	{
		EatFood(pNextNode, ps1, ps2);
	}
	else
	{
		NoFood(pNextNode, ps1);
	}
	//����Ƿ�ײǽ
	KillByWall(ps1);
	//����Ƿ�ײ�Լ�
	KillBySelf(ps1);
	//����Ƿ񱻱���ײ
	KillByOther(ps1, ps2);
	KillByOther(ps2, ps1);
	//���ͷ��ͷ
	Head_Head(ps1, ps2);
	Head_Head(ps2, ps1);
}

void Game_Run(pSnake ps1, pSnake ps2)//��Ϸ�����߼�
{
	//��ӡ������Ϣ
	PrintHelpInfo();
	do
	{
		//��ӡ������ʳ��Ȩ��
		set_pos(0, 26);
		printf("һ����ҵ��ܷ���:%d\n", ps2->_score);
		set_pos(30, 26);
		printf("������ҵ��ܷ���:%d\n",ps1->_score);
		set_pos(64, 9);
		printf("��ǰʳ��Ȩ��:%2d\n", ps1->_food_weight);
		//�������
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
		if (KEY_PRESS(0x57) && ps2->_dir != DOWN)//W��
		{
			ps2->_dir = UP;
		}
		else if (KEY_PRESS(0x53) && ps2->_dir != UP)//S��
		{
			ps2->_dir = DOWN;
		}
		else if (KEY_PRESS(0x41) && ps2->_dir != RIGHT)//A��
		{
			ps2->_dir = LEFT;
		}
		else if (KEY_PRESS(0x44) && ps2->_dir != LEFT)//D��
		{
			ps2->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			//��ͣ
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//�����˳�
			ps1->_status = END_NORMAL;
			ps2->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_OEM_6))
		{
			//����
			if (ps1->_sleep_time > 80)
			{
				ps1->_sleep_time -= 30;
				ps1->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(VK_OEM_4))
		{
			//����
			if (ps1->_food_weight > 2)
			{
				ps1->_sleep_time += 30;
				ps1->_food_weight -= 2;
			}
		}

		SnakeMove(ps1,ps2);//����һ���Ĺ���
		SnakeMove(ps2,ps1);//����һ���Ĺ���

		Sleep(ps1->_sleep_time);

	} while (ps1->_status == OK && ps2->_status == OK);
}

void Game_End(pSnake ps1, pSnake ps2)//��Ϸ�ƺ�
{

	//if (ps1->_status == OK)
	//{
	//	switch (ps2->_status)
	//	{
	//	case KILL_BY_SELF:
	//		wprintf(L"һ����ұ��Լ���ɱ��������һ�ʤ��");
	//		break;
	//	case KILL_BY_WALL:
	//		wprintf(L"һ����ұ�ǽ��ɱ��������һ�ʤ��");
	//		break;
	//	case KILL_BY_OTHER:
	//		wprintf(L"һ����ұ�������ҵ�ɱ��������һ�ʤ��");
	//		break;
	//	}
	//}
	//if (ps2->_status == OK)
	//{
	//	switch (ps1->_status)
	//	{
	//	case KILL_BY_SELF:
	//		wprintf(L"������ұ��Լ���ɱ��һ����һ�ʤ��");
	//		break;
	//	case KILL_BY_WALL:
	//		wprintf(L"������ұ�ǽ��ɱ��һ����һ�ʤ��");
	//		break;
	//	case KILL_BY_OTHER:
	//		wprintf(L"������ұ�һ����ҵ�ɱ��һ����һ�ʤ��");
	//		break;
	//	}
	//}
	//if (ps1->_status == END_NORMAL && ps2->_status == END_NORMAL)
	//	wprintf(L"�ѷָ��£�Ҫ������һ�֣�");

	system("cls");
	set_pos(42,12);
	if (ps1->_score > ps2->_score)
		printf("������һ�ʤ��");
	else if (ps1->_score < ps2->_score)
		printf("һ����һ�ʤ��");
	else
		printf("��ƽ�֡�");

	//�ͷ���������
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