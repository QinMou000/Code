#include "process.h"
#include <string.h>
#include <unistd.h>
#define style '#'

void process_v1()
{
	char buff[101] = { '0' };
	const char* stat = "|/-\\";
	int len = strlen(stat);
	for(int i = 0; i < 101; i++)
	{
		printf("[%-100s][%d%][%c]\r",buff,i,stat[i%len]);
		fflush(stdout);
		buff[i] = style;
		usleep(50000);
		
	}
	printf("\n");
}
