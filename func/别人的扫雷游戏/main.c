#include "game.h"


void menu()
{
	printf("*********************\n");
	printf("******  1.play  *****\n");
	printf("******  0.exit  *****\n");
	printf("*********************\n");

}


void test()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	//PrintBoard(mine, ROW, COL);
	PrintBoard(show, ROW, COL);

	//生成雷
	Setmine(mine, ROW, COL);
	PrintBoard(mine, ROW, COL);

	//排查雷
	Findmine(mine, show, ROW, COL);
}


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			test();
			break;
		case 0:
			printf("退出游戏!\n");
			break;
		default:
			printf("输入有误，请重新输入!\n");
			break;
		}
	} while (input);
	return 0;
}