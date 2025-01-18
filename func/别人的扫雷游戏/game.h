#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10   

//��ʼ������
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char ret);

//��ӡ����
void PrintBoard(char arr[ROWS][COLS], int row, int col);

//������
void Setmine(char arr[ROWS][COLS], int row, int col);

//�Ų���
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//չ����
char Around(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);