#include <stdio.h>
//int main()//�ɴ�С����
//{
//	int a, b, c, t;
//	scanf("%d,%d,%d", &a, &b, &c);
//	if (a < b)
//	{
//		t = a;
//		a = b;
//		b = t;
//	}
//	if (a < c)
//	{
//		t = a;
//		a = c;
//		c = t;
//	}
//	if (b < c)
//	{
//		t = b;
//		b = c;
//		c = t;
//	}
//	printf("%d,%d,%d", a, b, c);
//	return 0;
//}


//int main()//�ж�������
//{
//    int a = 1, b = 1, c = 1;
//    while (scanf("%d %d %d", &a, &b, &c) != EOF)
//    {
//        if (a < (b + c) && b < (a + c) && c < (b + a))
//        {
//            if (a == b && b == c)
//            {
//                printf("Equilateral triangle!\n");
//            }
//            else if (a == b || b == c || a == c)
//            {
//                printf("lsosceles triangle!\n");
//            }
//            else
//            {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else
//            printf("Not a triangle!\n");
//    }
//    return 0;
//}

//int main()//�������
//{
// float a, b,c,d, sum;
// float x = 0, y = 0;
//	for (a = 1; a <= 100; a = a + 2)
//	{
//		c = 1 / a;
//		x = x + c;
//	}
//	for (b = 2; b <= 100; b = b + 2)
//	{
//		d = 1 / b;
//		y = y + d;
//	}
//	sum = x - y;
// printf("%f",sum);
// return 0;
//}

//int main()//�ж�1��100���������г���9�ĸ���
//{
//	int a, b, c;
//	int num = 0;
//	for (a = 1; a <= 100; a++)
//	{
//		b = a % 10;
//		if (b == 9)
//		{
//			num+=1;
//		}
//		c = (a - b) / 10;
//		if (c == 9)
//		{
//			num+=1;
//		}
//	}
//	printf("%d", num);
//	
//	return 0;
//}

//int main()//���1000��2000���е�����
//{
//	int year, x;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (year % 4 == 0 && year % 100 != 0)
//		{
//			printf("%d\t", year);
//		}
//		else if (year % 400 == 0)
//		{
//			printf("%d\t", year);
//		}
//	}
//	return 0;
//}


//int main()//��10�������е����ֵ
//{
//	int a[10];
//	int i, t;
//	for (int i = 0; i <= 9; i++)//����10������
//	{
//		scanf("%d",&a[i]);
//	}
//	int max = a[0];//�ٶ�a[0]Ϊ���ֵ
//	for (int i = 1; i <= 9; i++)
//	{
//		if (max < a[i])
//			{
//			max = a[i];//�������ֵ
//			}
//	}
//	printf("���ֵΪ��%d\n", max);//������ֵ
//	
//	return 0;
//}
//int main()
//{
//	srand((unsigned int)time(NULL));
//	while (1)
//	{
//		printf("%d ",rand()%100+1);
//	}
//
//
//}







//#include<stdlib.h>
//#include<time.h>
//
//int menu()//�˵�����
//{
//	printf("************\n");	
//	printf("***1 play **\n");
//	printf("***0 exit **\n");
//	printf("************\n");
//	return 0;
//}
//void game()//��Ϸ����
//{
//	int chance;
//next:
//	printf("������Լ��ö��ٴλ�������ֲ³�����\n");
//	scanf("%d",&chance);
//	if (chance == 0)
//	{
//		printf("�������\n");
//		goto next;
//	}
//	else if (chance > 6)
//	{
//		printf("������˵���ҍ�ĳ�˿������㣡\n");
//	}
//	int guess;
//	int ret = rand() % 100 + 1;//�������1-100֮�������
//	//printf("%d ", ret);
//	printf("��������µ����֣�\n(ע��:��ֻ��%d�λ���!)\n",chance);
//	while (chance)
//	{
//		scanf("%d", &guess);
//		if (ret > guess)
//		{
//			printf("��С��\n");
//			printf("�㻹��%d�λ���!\n", chance - 1);
//
//		}
//		else if (ret < guess)
//		{
//			printf("�´���\n");
//			printf("�㻹��%d�λ���!\n", chance-1);
//		}
//		else
//		{
//			printf("��ϲ�㣡�¶��ˣ�������%d\n",ret);
//			break;
//		}
//		chance--;
//	}
//	if (chance == 0)
//	{
//		printf("��Ϸʧ��!\n");
//	}	
//}
//int main()//                                  ��������Ϸ
//{
//	int input;
//	srand((unsigned int)time(NULL));//���ɲ�ͬ��ʱ���
//	do
//	{
//		menu();
//		printf("��ѡ��:\n");
//		scanf("%d", &input);//ѡ���Ƿ������Ϸ
//
//		switch (input)
//		{
//		case 1:
//			printf("<��1-100֮�������>\n");
//			game();
//				break;
//		case 0:
//			printf("<�˳���Ϸ>\n");
//				break;
//		default:
//			printf("<����������������룡>\n");
//				break;
//		}
//	} while (input);
//}


//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	for(int i=0;i<10;i++)
//	printf("%d ",arr[i]);
//}
//int main()
//{
//	for (int i = 1; i <=100; i++)
//	{
//		printf("*");
//		if (i % 10 == 0)
//			printf("\n");
//	}
//}

//#include <stdio.h>
//int main()
//{
//    int arr[] = { 1,2,(3,4),5 };
//    printf("%d\n", sizeof(arr));
//    return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a = 0, b = 0;
//	for (a = 1, b = 1; a <= 100; a++)
//	{
//		if (b >= 20) break;
//		if (b % 3 == 1)
//		{
//			b = b + 3;
//			continue;
//		}
//		b = b - 5;
//	}
//	printf("%d\n", a);
//	return 0;
//}
//#include<string.h>
//#include <stdio.h>
//int main()
//{
//    char str[] = "hello bit";
//    printf("%d %d\n", sizeof(str), strlen(str));
//    return 0;
//}


//int mian()
//{
//	int x;
//	scanf("%d ",&x);
//
//	if (x % 2 == 0)
//		printf("%d��ż��\n");
//	else
//		printf("%d������\n");
//	return 0;
//}

//int main()
//{
//	int a;
//	scanf("%d",&a);
//
//	if (a > 0)
//		printf("����\n");
//	else if (a < 0)
//		printf("����\n");
//	else
//		printf("Ϊ��\n");
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	if (a > 2)
//	{
//		if (a > 4)
//			printf("wq���Ǵ�˧��");
//    else
//			printf("wq�Ǵ�˧��");
//	}
//	else
//	return 0;
//}
//
//int main()
//{
//	int a;
//	scanf("%d",&a);
//	a = a % 2;
//	switch (a)
//	{
//	case 0:
//		printf("ż��\n"); break;
//	case 1:
//		printf("����\n"); break;
//
//	}
//}
//
//int main()
//{
//	int num;
//	scanf("%d", &num);
//	switch (num)
//	{
//	case 1:
//	case 2:
//	case 3:
//	default:printf("�������"); break;
//	case 4:
//	case 5:printf("��ѧ"); break;
//	case 6:
//	case 7:printf("�ż٣�"); break;
//	
//	}
//	return 0;
//}

//int main()//�žų˷���
//{
//	int a,b,i;
//		for (a = 1; a <= 9;a++)
//		{
//			for (b = 1; b <= a; b++)
//			{
//					printf("%d*%d=%d\t",b,a,a*b);
//			}
//			printf("\n");
//		}	
//	
//	return 0;
//}



//int main()//���Լ��
//{
//	int i, j, max, min;
//	scanf("%d %d", &i, &j);
//	if (i > j)
//	{
//		max = i;
//		min = j;
//	}
//	else
//	{
//		max = j;
//		min = i;
//	}
//	for (int x =max; x >=2; x--)
//	{
//		if (i % x == 0 && j % x == 0)
//		{
//			printf("%d ", x);
//			break;
//		}
//	}
//	return 0;
//}


//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		//�ж�i�Ƿ�������
//		//������������ʹ�ӡ����������������
//		//��2~i-1֮�������ȥ�����Գ�i�����������һ������������i��i�Ͳ�������
//		//������е����ֶ���������i��i��������
//		int j = 0;
//		int flag = 1;//����i������
//		for (j = 2; j <= i - 1; j++)//2~8
//		{
//			if (i % j == 0)
//			{
//				flag = 0;//֤����������
//				break;
//			}
//		}
//		if (flag == 1)//������
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}


////int main()
//{
//	int a = 5;
//	int b = a % 2;
//	printf("%d", b);
//}


//int main()
//{
//	int a;
//
//	scanf("%d",&a);
//
//	printf("%5d",a);
//	printf("hehe");
//}

//
//#include <stdio.h>
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	//i = a++||++b||d++;
//	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);
//	return 0;
//}
//
//
//#include<stdio.h>
//int main()//                                           ������Ĵ��롷
//{
//    int max, mid, min;
//    {
//        for (max = 0; max <= 33; max++)//ȫ�ô������33ͷ
//        {
//            for (mid = 0; mid <= 50; mid++)//ȫ���������50ͷ
//            {
//                min = 100 - max - mid;  //С��=����-����-С��
//                if ((max * 3 + mid * 2 + min * (1 / 2) == 100)&&(min%2==0)) //�ж�ȡֵ�Ĵ����������Ե�����+�����������Ե�����+С���������Ե������Ƿ�=100
//                {
//                    printf("����=%d ����=%d С��=%d\n", max, mid, min);//������ֱ��ӡ���С�С�������
//                }
//            }
//        }
//    }
//    return 0;
//}



//#include<stdio.h>
//int main()
//{
//	int big, mid, small, sum = 0;
//	for (big = 0; big < 33; big++)
//		for (small = 0; small < 100; small += 2)
//			for (mid = 0; mid < 50; mid++)
//			{
//				if (3 * big + 2 * mid + small / 2 == 100 && big + mid + small == 100)
//				{
//					printf("big:%d\tmid:%d\tsmall:%d\n", big, mid, small);
//					sum++;
//				}
//			}
//	printf("%d\n", sum);
//}



//#include <stdio.h>
//
//int main() {
//    int big, medium, small;
//    for (big = 1; big <= 33; big++) 
//    {
//        for (medium = 1; medium <= 50; medium++) 
//        {
//            small = 100 - big - medium;
//            if (big * 3 + medium * 2 + small / 2 == 100 && small % 2 == 0) 
//            {
//                printf("����%d, ����%d, С��%d\n", big, medium, small);
//            }
//        }
//    }
//    return 0;
//}
//
//int main()//ʮ�����ľ�ֵ������棩
//{
//	int a[10];
//	int sum = 0, average;
//	for (int i = 0
//		; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (int i = 0;i < 10; i++)
//	{
//		sum = sum + a[i];
//	}
//	average = sum / 10;
//	printf("%d",average);
//}

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		printf("%d ", i);
//		++i;
//	}
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	do
//	{
//		printf("%d ", i);
//		i += 1;
//	} while (i<=10);
//
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 4)
//			break;
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 4)
//			continue;
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

//int main()
//{
//	
//	for (int i = 1; i <= 10; i++)
//	{
//		if (i == 4)
//			break;
//		printf("��ĩ���ӱ���\n");
//	}
//	return 0;
//}


//int main()
//{
//
//	for (int i = 1; i <= 10; i++)
//	{
//		if (i == 4)
//			continue;
//		printf("%d ",i);
//	}
//	return 0;
//}
// 
// 
//int main()
//{
//	printf("haha\n");
//	goto next;
//	printf("hehe\n");
//next:
//	printf("������hehe�Ĵ�ӡ\n");
//
//}

//int main()//ţ���ͼ��
//{
//	int a=3;
//	while (scanf("%d", &a) != EOF);
//	{
//		for (int i = 0; i <a; i++)
//		{
//			for (int j = 0; j < a; j++)
//			{
//				if (i == j || i + j == a - 1)
//				{
//					printf("*");
//				}
//				else
//				{
//					printf(" ");
//				}
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}

//int main()//�����ͼ��
//{
//	int a = 3;
//	while (scanf("%d", a) != EOF)
//	{
//		for (int i = 0; i < a; i++)
//		{
//			for (int j = 0; j < a; j++)
//			{
//				if (i == 0 || i == a - 1 || j == 0 || j == a - 1)
//					printf("* ");
//				else
//					printf("  ");
//			}
//			printf("\n");
//		}
//	}
//}

//int mian()
//{
//	int i,j;
//	scanf("%d %d",&i,&j);
//	int arr1[i][j] = { 0 };
//	for (int a=0;a<i;a++)
//	{
//		for (int b = 0; b < j; b++)
//		{
//			scanf("%d ",arr1[i][j]);
//		}
//	}
//	int arr2[j][i] = { 0 };
//	
//	for (int x = 0; x <= i * j; x++)
//	{
//		arr2[][] = arr1[][];
//	}
//	return 0;
//}

//#include <stdio.h>
//int main() //��ת����
//{
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF)
//    {
//        int arr[a][b];
//        for (int i = 0; i < a; i++)
//        {
//            for (int j = 0; j < b; j++)
//            {
//                scanf("%d", &arr[i][j]);
//            }
//        }
//
//        for (int i = 0; i < b; i++)
//        {
//            for (int j = 0; j < a; j++)
//            {
//                printf("%d", arr[j][i]);
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}

//int main()
//{
//	int i,j;
//	int arr[10];
//	for(int i = 0;i <= 9; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	for(int j = 9;j >= 0; j--)
//	{
//		printf("%d ",arr[j]);
//	}
//	return 0;
//}
// 
// 
// 
// 
// 
//int main()  //�������кϲ�
//{
//	int m, n;
//	scanf("%d %d", &m, &n);
//	int arr1[1000];
//	int arr2[1000];
//	for (int i = 0; i < m; i++)
//	{
//		scanf("%d ", &arr1[i]);
//	}
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%d ", &arr2[i]);
//	}
//	int i = 0;
//	int j = 0;
//	while (i < m && j < n)
//	{
//		if (arr1[i] < arr2[j])
//		{
//			printf("%d ", arr1[i]);
//			i++;
//		}
//		else
//		{
//			printf("%d ",arr2[j]);
//			j++;
//		}
//	}
//	while (i < m)
//	{
//		printf("%d ", arr1[i]);
//		i++;
//	}
//	while (j < n)
//	{
//		printf("%d ",arr2[j]);
//		j++;
//	}
//}


//int main()//����Ԫ��
//{
//	int a[] = {1,3,5,7,9};
//	int b[] = { 2,4,6,8,10 };
//	int c[5];
//	for (int i = 0; i < 5; i++)
//	{
//		c[i] = a[i];
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		a[i] = b[i];
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		b[i] = c[i];
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", b[i]);
//	}
//	printf("\n");
//	return 0;
//}