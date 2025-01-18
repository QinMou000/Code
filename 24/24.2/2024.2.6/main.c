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

 void calus(int (*pfs)(int,int))
 {
	 int x = 0;
	 int y = 0;
	 int z = 0;
	 printf("�����������");
	 scanf("%d %d", &x, &y);
	 z = pfs(x,y);
	 //  �Զ��������
	 //		 plana���ÿ⺯��itoa
	 //		 planb���֡�����ʵ��
	 printf("ʮ���ƽ��:%d\n",z);
	 printf("�����ƽ��:");
	 Print_Binary(z);
	 printf("\n");
 }

int main()
{
	menu();
	int input = 0;
	do
	{
		printf("�����룺");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			calus(add);
			break;
		case 2:
			calus(sub);
			break;
		case 3:
			calus(mul);
			break;
		case 4:
			calus(divs);
			break;
		case 5:
			calus(Shift_right_bit);
			break;
		case 6:
			calus(Shift_left_bit);
			break;
		case 7:
			calus(Bitwise_with);
			break;
		case 8:
			calus(Bitwise_or);
			break;
		case 9:
			calus(Bitwise_XOR);
			break;
		case 0:
			printf("���˳���");
			break;
		default:
			printf("��������������룡");
			break;
		}

	} while (input);

	return 0;
}