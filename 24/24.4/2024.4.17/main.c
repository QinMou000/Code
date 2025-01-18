#define _CRT_SECURE_NO_WARNINGS 1
#include "snake.h"


void test()
{	
	char ch = 'y';
	
	do
	{
		system("cls");
		//创建贪吃蛇
		pSnakeNode pSnake = NULL;

		Snake snake = { 0 };

		//初始化游戏
		Game_Start(&snake);

		//运行游戏
		Game_Run(&snake);

		////结束游戏
		Game_End(&snake);
		set_pos(20, 15);
		printf("再来一局？（Y/N）");
		ch = getchar();
		/*while (getchar() != '\n');*/
		getchar();
	} while (ch == 'y' || ch == 'Y');
	set_pos(0,25);
}


int main()
{
	//设置本地环境
	setlocale(LC_ALL,"");
	srand((unsigned int)time(NULL));
	test();

	return 0;
}
