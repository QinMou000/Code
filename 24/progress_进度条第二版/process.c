#include<stdio.h>

void process_v2(double total, double cur)
{
	char buff[101] = { '0' };
	const char* lable = "|/-\\";
	int len = strlen(lable);

	int num =(int)(cur*100/total);
	for(int i = 0; i < num; i++)
	{
		buff[i] = '#';
	}
	double rate = (cur*100)/total;
	static count = 0;
	printf("\033[32m[%-100s][%.1f%%][%c]\033[0m\r",buff,rate,lable[count%len]);

	count++;	
	fflush(stdout);
}


int main()
{
	int t = 1024;
	int ad = 0;
	while(ad <= 1024)
	{
		process_v2(t,ad);
		ad++;
		usleep(5000);
	}
	printf("\033[32m\n\rcomplete!!!\033[0m\n");
	return 0;
}
