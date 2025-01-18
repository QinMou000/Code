#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void menu()
{
	printf("****************************\n");
	printf("***   1��>'+'  2��>'-'   ***\n");
	printf("***   3��>'*'  4��>'/'   ***\n");
	printf("***   5��>'>>' 6��>'<<'  ***\n");
	printf("***   7��>'&'  8��>'|'   ***\n");
	printf("***        9��>'^'       ***\n");
	printf("****************************\n");
	printf("***        0.exit       ****\n");
	printf("****************************\n");
}

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int divs(int x, int y)
{
	return x / y;
}

int Shift_right_bit(int x, int y)
{
	return x >>= y;
}

int Shift_left_bit(int x, int y)
{
	return x <<= y;
}

int Bitwise_with(int x, int y)
{
	return x & y;
}

int Bitwise_or(int x, int y)
{
	return x | y;
}

int Bitwise_XOR(int x, int y)
{
	return x ^ y;
}

void Print_Binary(unsigned int x)
{
	if (x > 1)
	{
		Print_Binary(x >> 1);
	}
	putchar((x & 1) ? '1' : '0');
}

// void calu(int (*pf)(int, int))
//{
//	 int x = 0;
//	 int y = 0;
//	 int z = 0;
//	 printf("�����������");
//	 scanf("%d %d", &x, &y);
//	 z = pf(x, y);
//	 printf("ʮ���ƽ��:%d\n", z);
//	 printf("�����ƽ��:\n");
//	 Print_Binary(z);
//	 printf("\n");
//}

int main()
{
	int input = 0;
	int (*pf[10])(int, int) = { NULL,add ,sub,mul,divs,Shift_right_bit,Shift_left_bit,Bitwise_with,Bitwise_or,Bitwise_XOR};
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d",&input);
		if (input >= 1 && input <= 9)
		{
			int x = 0;
			int y = 0;
			int z = 0;
			printf("�������������");
			scanf("%d %d",&x,&y);
			z = pf[input](x,y);
			printf("ʮ���ƽ����%d\n",z);
			printf("�����ƽ����");
			Print_Binary(z);
			printf("\n");
		}
		else if(input==0)
		{
			printf("���˳���");
		}
		else
		{
			printf("���������������");
		}

	} while (input);

	return 0;
}