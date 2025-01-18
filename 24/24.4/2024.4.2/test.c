#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isPathCrossing(char* path)
{
	int arr[2][1000];
	arr[1][0] = 0;
	arr[0][0] = 0;
	int x = 0;
	int y = 0;
	int size = strlen(path);
	for (int i = 1; i <= size; i++)
	{
		switch (*path)
		{
		case 'N':
			y++;
			arr[0][i] = x;
			arr[1][i] = y;
			break;
		case 'S':
			y--;
			arr[0][i] = x;
			arr[1][i] = y;
			break;
		case 'E':
			x++;
			arr[0][i] = x;
			arr[1][i] = y;
			break;
		case 'W':
			x--;
			arr[0][i] = x;
			arr[1][i] = y;
			break;
		}
		for (int j = 0; j < i; j++)
		{
			if ((arr[0][i] == arr[0][j]) && (arr[1][i] == arr[1][j]))
				return true;
		}
		path++;
	}
	return false;
}
int main()
{
	char* path = "SN";
	printf("%d\n",isPathCrossing(path));
}