#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10   

//初始化棋盘
void InitBoard(char arr[ROWS][COLS], int rows, int cols, char ret);

//打印棋盘
void PrintBoard(char arr[ROWS][COLS], int row, int col);

//生成雷
void Setmine(char arr[ROWS][COLS], int row, int col);

//排查雷
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//展开雷
char Around(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);