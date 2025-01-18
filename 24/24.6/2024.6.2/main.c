#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//int main()
//{
	//int x, i;
	//for (i = 1; i <= 100; i++)
	//{
	//	x = i;
	//	if (++x % 2 == 0)
	//		if (++x % 3 == 0)
	//			if (++x % 7 == 0)
	//				printf("%d ", x);
	//}
	//for (int i = 1; i++ < 4;)
	//	;
	//printf(" %d\n", m[1][0] + n[0][0]); 
	//printf("%d\n", m[0][1] + n[1][0]);
	//int i;
	//for (i = 2, i == 0;)
	//	printf("%d", i--);
	//int i, j, k;
	//for (i = 2; i < 6; i++, i++)
	//{
	//	k = 1;
	//	for (j = i; j < 6; j++)  
	//		k = k + j;
	//}
	//printf("%d\n", k);
	//int t, x;
	//for (t = 1; t <= 2; t++)
	//{
	//	scanf("%d", &x);
	//	if(x < 0)
	//		continue;
	//	printf("%3d", t);
	//}
	//int i, j, x = 0;
	//for (i = 0; i < 2; i++)
	//{
	//	x++;
	//	for (j = 0; j <= 3; j++)
	//	{
	//		if (j % 2)
	//			continue;
	//		x++;
	//	}
	//	x++;
	//}
	//printf("x = %d\n", x);
	//int x;
	//for(x = 100; x <= 200; x++)
	//	if (x % 7 != 0 && x % 3 != 0) 
	//		printf("%d\n", x);
	
	
	//输入数据
	//定义最大最小
	//遍历
	//int num[10], i,max,min;
	//printf("请输入十个整数\n");
	//for (i = 0; i < 10; i++)
	//{
	//	scanf("%d", &num[i]);
	//}
	//max = num[5];
	//min = num[1];
	//for (int i = 0; i < 10; i++)
	//{
	//	if (min > num[i])
	//		min = num[i];
	//	if (max < num[i])
	//		max = num[i];
	//}
	//printf("max:%d\nmin%d\n", max, min);

	//int n;
	//scanf("%d",&n);
	//
	//for (int i = n; i < 0; i--)
	//{
	//	int lastnum = i * 2 - 1;
	//	for (int j = 0; j < lastnum; j++)
	//	{
	//		if ()
	//			printf("*");
	//		else
	//			printf(" ");
	//	}
	//	printf("\n");
	//}
	//int a[5] = {1,2,3,4,5};
	//printf("%p", a);
	//char c[] = "\t\v\\\0will\n";
	//printf("%d", strlen(c));
//}

//int main()
//{
//	int n = 0x11223344;
//	int* pi = &n;
//	*pi = 0;
//	return 0;
//}
/************************/
//int main()
//{
//	int n = 0x11223344;
//	char* pc = (char*)&n;
//	*pc = 0;
//	return 0;
//}

//int main()
//{
//
//	int a[5] = { 5,2,3,4,5 };
//	int* pa = a;
//	for (int i = 0; i < 5; i++)
//		printf("%d ", *(a + i));
//	printf("\n");
//	for (int i = 0; i < 5; i++)
//		printf("%d ", *a + i);
//
//	printf("\n%d", &a[4] - &a[0]);
//	return 0;
//}

//void main()
//{
//	int x[8] = { 8,7,6,5,0 }, * s;
//	s = x + 3;
//	printf("%d ", s[2]);//*(s + 2)
//}
//void main()
//{
//	char a[] = "language", * p; p = a;
//	while (*p != 'u')
//	{
//		printf("%c", *p - 32); p++;
//	}
//}
//void main()
//{
//	int a[] = { 2,4,6,8,10 };
//	int y = 1, x, * p; 
//	p = &a[1];
//	for (x = 0; x < 3; x++) 
//		y += *(p + x);
//	printf("%d\n", y);
//}
//void main()
//{
//	char s[] = "ABCD", * p;
//	for (p = s + 1; p < s + 4; p++)
//		printf("%s\n", p);
//}

int main()
{
	//int t[3][3];
	//t[1][2] = 2;
	//int (*pt)[3] = t[0];
	//printf("%d", * (*(pt + 1) + 2));
	int x[] = { 1,2,3,4,5,6 }, * p = &x[2];
	printf("%d\n", *(p));
	p++;
	printf("%d",*p);

	return 0;
}
