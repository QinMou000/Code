#define _CRT_SECURE_NO_WARNINGS 1
#include "snake.h"


void test()
{	
	char ch = 'y';
	
	do
	{
		system("cls");
		//����̰����
		pSnakeNode pSnake = NULL;

		Snake snake = { 0 };

		//��ʼ����Ϸ
		Game_Start(&snake);

		//������Ϸ
		Game_Run(&snake);

		////������Ϸ
		Game_End(&snake);
		set_pos(20, 15);
		printf("����һ�֣���Y/N��");
		ch = getchar();
		/*while (getchar() != '\n');*/
		getchar();
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
