#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{

	//char* str;

	//str = "a";
	//printf("%p",str);
	//int a[3][5] = { 1565,45,5,85,5,123,489,51,156,1,5,5,8654 };


	//char s[] = { 's','h','a','n','g','h','a','i' };
	//char str[] = { "shanghai" };
	//char str2[20];
	//strcmp();
	//char a[30];
	//char* p = a;
	//a[30] = "this is a C program";
	//a = "this is a C program";
	//*p = "this is a C program";
	//int k = 1; 
	//int n = 263;
	//do
	//{ 
	//	k *= n % 10;
	//	n /= 10; 
	//} while (n);
	//int t = 1, s = 0;
	//for (int i = 0; i < 101 ; i+=2)
	//{
	//	t = t * i; 
	//	s = s + t;  
	//	t = -t / i;
	//}
//		int x, y;
		//for (x = 30, y = 0;  y < 20; x--, y++)
		//	x /= 2, y += 2;
		//printf("x = %d, y = %d\n", x, y);
	//static char ch[] = "623";
	//int a, s = 0;
	//for (a = 0; ch[a] >= '0' && ch[a] <= '9'; a++)
	//s = 10 * s + ch[a] - '0';
	//printf("%d", s);
	//return 0;

	//char a[20] = " You are a girl";
	//char* p = a;
	//char** ptr = &p;

	//printf("%c",**ptr);
	//ptr++;
	//printf("\n%c", **ptr);
	int a = 1; 
	int b = 2;
	int c = 2;
	int t;
	while (a < b < c) { t = a; a = b; b = t; c--; }
	printf("%d%d%d", a, b, c);

}