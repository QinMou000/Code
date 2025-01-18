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

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ����
	//PrintBoard(mine, ROW, COL);
	PrintBoard(show, ROW, COL);

	//������
	Setmine(mine, ROW, COL);
	PrintBoard(mine, ROW, COL);

	//�Ų���
	Findmine(mine, show, ROW, COL);
}


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("������:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			test();
			break;
		case 0:
			printf("�˳���Ϸ!\n");
			break;
		default:
			printf("������������������!\n");
			break;
		}
	} while (input);
	return 0;
}