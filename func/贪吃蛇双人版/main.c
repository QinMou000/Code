#define _CRT_SECURE_NO_WARNINGS 1
#include "snake.h"

void test()
{	
	char ch = 'y';
	
	do
	{
		system("cls");
		//����̰����
		//pSnakeNode pSnake = NULL;

		Snake snake1 = { 0 };

		Snake snake2 = { 0 };

		//��ʼ����Ϸ
		Game_Start(&snake1, &snake2);

		//������Ϸ
		Game_Run(&snake1,&snake2);

		////������Ϸ
		Game_End(&snake1,&snake2);

		set_pos(38, 15);
		printf("����һ�֣���Y/N��");
		ch = getchar();

		while (getchar() != '\n');
	
	} while (ch == 'y' || ch == 'Y');
	
	set_pos(0,25);
}

int main()
{
	//���ñ��ػ���
	setlocale(LC_ALL,"");
	srand((unsigned int)time(NULL));
	test();

	return 0;
}