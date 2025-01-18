#include "game.h"

//��ʼ������
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

//��ӡ����
void PrintBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("----------ɨ����Ϸ-----------\n");
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

//������
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


//�Ų���
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - EASY_COUNT)
	{
		printf("����������:");
		scanf_s("%d %d", &x, &y);
		//����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				//��λ������
				if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
					PrintBoard(mine, ROW, COL);
					break;
				}
				else
				{
					//չ����
					Around(mine, show, x, y);
					PrintBoard(show, ROW, COL);
					win++;
				}
			}
			else
			{
				printf("���벻�Ϸ�������������\n");
			}
		}
		else
		{
			printf("���벻�Ϸ�\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("���׳ɹ�\n");
		PrintBoard(mine, ROW, COL);
	}
}


//ͳ����
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

//չ����
char Around(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	if (x <= ROW && x >= 1 && y <= COL && y >= 1 && show[x][y] == '*' && mine[x][y] != '1')
	{
		int sum = Getmine(mine, x, y);
		if (sum == 0)//����Χ���ף��򽫸�λ�ø�ֵΪ�� ��
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
		else//�����ף��򽫸�λ�ø�ֵΪ��������õ���Χ�м�����
		{
			show[x][y] = sum + '0';
		}
	}
}