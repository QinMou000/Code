#include "head.h"

void test()
{
	char show[ROWS][COLS] = { 0 };
	char mine[ROWS][COLS] = { 0 };

	init_board(show, ROWS, COLS, '*');
	init_board(mine, ROWS, COLS, '0');

	//display_board(show, ROW, COL);
	//display_board(mine, ROW, COL);

	set_mine(mine,ROW,COL);
	display_board(show, ROW, COL);
	//display_board(mine, ROW, COL);

	find_mine(mine, show, ROW, COL);

}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("������:\n");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				test(); 
				continue;
			case 0:
				printf("��Ϸ����\n"); 
				break;
			default:
				printf("�����������������룡\n"); 
				break;
		}
	} while (input);
	return 0;
}