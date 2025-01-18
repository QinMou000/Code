#define _CRT_SECURE_NO_WARNINGS 1

#include<windows.h>
#include<iostream>
using namespace std;
#define style '#'

void process_v1()
{
	char buff[101] = { '0' };
	const char* stat = "|/-\\";
	int len = strlen(stat);
	for (int i = 0; i < 101; i++)
	{
		printf("[%-100s][%d%%%][%c]\r", buff, i, stat[i % len]);
		fflush(stdout);
		buff[i] = style;
		Sleep(100);
	}
	printf("\n");
}

int main()
{
	process_v1();

	return 0;
}