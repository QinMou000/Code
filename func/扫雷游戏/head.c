#include "head.h"
void menu(void)
{
	printf("*************************************\n");
	printf("*************  0. Exit **************\n");
	printf("*************************************\n");
	printf("*************  1. Play **************\n");
	printf("*************************************\n");
}

void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i <= rows;  i++)
	{
		for (int j = 0; j <= cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----欢 迎 来 到 扫 雷 游 戏------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%2d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%2c ", board[i][j]);
		}
		printf("\n");
	}
}

void set_mine(char board[ROWS][COLS], int row, int col)
{

	int count=mid_count;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
	
		if(board[x][y]=='0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//int find_mine_count(char mine[ROWS][COLS], int x, int y)
//{
//	int count = 0;
//	int i = 0;
//	for (i = x - 1; i <= x + 1; i++)
//	{
//		int j = 0;
//		for (j = x - 1; j <= x + 1; j++)
//		{
//			count += (mine[i][j]-'0');
//		}
//	}
//	return count;
//}

int find_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] +
		mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] - 8 * '0';

}

void find_mine(char mine[ROWS][COLS],char show[ROWS][COLS],int row, int col)
{
	int win = 0;
	int x = 0;
	int y = 0;
	while (win < row * col - easy_count)
	{
		printf("\n请输入要排除的坐标:");

		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("\n恭喜你被炸死了！\n");
					display_board(mine, ROW, COL);
				}
				else
				{
					int mine_count = find_mine_count(mine, x, y);
					show[x][y] = mine_count+'0';
					display_board(show, ROW, COL);
					win++;
				}
			}
			else
			{
				printf("该坐标已被排查，请重新输入坐标！\n");
			}
		}
		else
		{
			printf("坐标非法，重新输入！\n");
		}
	}
	if (win == row * col - easy_count)
	{
		printf("\n很遗憾你把雷全部排查完了，游戏结束！\n");
	}
}