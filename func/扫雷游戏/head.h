#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define easy_count 10
#define mid_count 25
#define max_count 50
//�˵�
void menu(void);

//��ʼ������
void init_board(char board[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void display_board(char board[ROWS][COLS], int row, int col);

//������
void set_mine(char board[ROWS][COLS], int row, int col);

//�ų���
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
