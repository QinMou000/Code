#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#if 1
#include <stdio.h>

int main()
{
    int data[9][9];
    int i = 0;
    int j = 0;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            data[i][j] = 1;
        }
    }
    for (i = 1; i < 9; i++)
    {
        for (j = 1; j < i; j++)
        {
            data[i][j] = data[i - 1][j] + data[i - 1][j - 1];
        }
    }
    for (i = 0; i < 9; i++)
    {
        for (int k = 0; k < 26 - (3 * i); k++)
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            printf("%6d", data[i][j]);
        }
        printf("\n");
    }
    return 0;
}

#endif