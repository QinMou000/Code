#include "game.h"

//初始化棋盘
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char ret)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = ret;
		}
	}
}

//打印棋盘
void PrintBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------扫雷游戏-----------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

//生成雷
void Setmine(char arr[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}


//排查雷
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("请输入坐标:");
		scanf_s("%d %d", &x, &y);
		//坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				//该位置是雷
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					PrintBoard(mine, ROW, COL);
					break;
				}
				else
				{
					//展开雷
					Around(mine, show, x, y);
					PrintBoard(show, ROW, COL);
					win++;
				}
			}
			else
			{
				printf("输入不合法，请重新输入\n");
			}
		}
		else
		{
			printf("输入不合法\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("排雷成功\n");
		PrintBoard(mine, ROW, COL);
	}
}


//统计雷
int Getmine(char arr[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = x - 1; i <= x + 1; i++)
	{
		for (j = y - 1; j <= y + 1; j++)
		{
			if (arr[i][j] == '1')
			{
				count++;
			}
		}
	}
	return count;
}

//展开雷
char Around(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	if (x <= ROW && x >= 1 && y <= COL && y >= 1 && show[x][y] == '*' && mine[x][y] != '1')
	{
		int sum = Getmine(mine, x, y);
		if (sum == 0)//若周围无雷，则将该位置赋值为‘ ’
		{
			show[x][y] = ' ';
			for (i = (x - 1 > 1 ? x - 1 : 1); i <= (x + 1 > ROW ? ROW : x + 1); i++)
			{
				for (j = (y - 1 > 1 ? y - 1 : 1); j <= (y + 1 > COL ? COL : y + 1); j++)
				{
					Around(mine, show, i, j);
				}
			}
		}
		else//若有雷，则将该位置赋值为几，代表该点周围有几个雷
		{
			show[x][y] = sum + '0';
		}
	}
}