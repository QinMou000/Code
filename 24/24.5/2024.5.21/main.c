#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//3、从键盘输入一个字符串，将其中的小写字母全部转换成大写字母，
// 然后输出到一个磁盘文件“test.dat”中保存，再从该文件中读出字符串并显示出来。
//int main()
//{
//	char s[10000];
//	scanf("%s",s);
//	char* cur = s;
//	while (*cur != '\0')
//	{
//		if (*cur <= 'z' && *cur >= 'a')
//			*cur -= 32;
//		cur++;
//	}
//	const char* file = "test.txt";
//	FILE* fin = fopen(file, "w");
//	if (fin == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//	cur = s;
//	while (*cur)
//	{
//		fprintf(fin, "%c\n", cur);
//		cur++;
//	}
//	fclose(fin);
//
//	file = "test.txt";
//	FILE* fout = fopen(file, "r");
//	if (fout == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//	char x;
//	while (printf("%c", fscanf(fout, "%c", &x) > 0))
//	{
//		printf("%c", x);
//	}
//
//	return 0;
//}

//4、有五个学生，每个学生有3门课的成绩，从键盘输入数据。
// （包括学号、姓名、三门课的成绩）、计算出平均成绩，
// 将计算出的平均分存放在磁盘文件“stud.dat”中。
//typedef struct Student
//{
//	char name[20];
//	char num[20];
//	int score[3];
//	int ave;
//}Stu;
//int main()
//{
//	Stu s1;
//	Stu s2;
//	Stu s3;
//	scanf("%s %s", s1.name, s1.num);
//	for (size_t i = 0; i < 2; i++)
//	{
//		scanf("%d",&s1.score[i]);
//	}
//	scanf("%s %s", s2.name, s2.num);
//	for (size_t i = 0; i < 2; i++)
//	{
//		scanf("%d", &s2.score[i]);
//	}
//	scanf("%s %s", s3.name, s3.num);
//	for (size_t i = 0; i < 2; i++)
//	{
//		scanf("%d", &s3.score[i]);
//	}
//	s1.ave = (s1.score[0] + s1.score[1] + s1.score[2]);
//	s2.ave = (s2.score[0] + s2.score[1] + s2.score[2]);
//	s3.ave = (s3.score[0] + s3.score[1] + s3.score[2]);
//	const char* file = "test.txt";
//	FILE* fin = fopen(file, "w");
//	if (fin == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//	
//	fprintf(fin, "%d\n", &s1.ave);
//	fprintf(fin, "%d\n", &s2.ave);
//	fprintf(fin, "%d\n", &s3.ave);
//
//}


//5、编写程序，生成10000个随机整数，
// 并将其保存到磁盘文件test.txt中。
// 再从文件test.txt中读入这些整数到内存中，
// 对其进行排序，将排序后的结果输出到文件data.txt中。
//
//void CreateNDate()
//{
//	// 造数据
//	int n = 100000;
//	srand((int)time(0));
//	const char* file = "data.txt";
//	FILE* fin = fopen(file, "w");
//	if (fin == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//
//	for (size_t i = 0; i < n; ++i)
//	{
//		int x = rand() % 1000000;
//		fprintf(fin, "%d\n", x);
//	}
//
//	fclose(fin);
//}
//
//void Swap(int* x, int* y)
//{
//	int tmp;
//	tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//void AdjustDown(int* a, int size, int parent)
//{
//	int child = parent * 2 + 1;
//	while (child < size)//这里不能像up部分都写到一起！
//	{
//		if (a[child] > a[child + 1] && child + 1 < size)//&&后面的东西很重要！！！
//			child++;
//		if (a[parent] > a[child])//child变化之后再判断。
//		{
//			Swap(&a[parent], &a[child]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//			break;
//	}
//}
//
//void PrintTopK()
//{
//	int k;
//	scanf("%d", &k);
//	const char* file = "data.txt";
//	FILE* fout = fopen(file, "r");
//	if (fout == NULL)
//	{
//		perror("fopen error");
//		return;
//	}
//	int* a = (int*)malloc(sizeof(int) * k);
//	if (a == NULL)
//	{
//		perror("malloc is fail");
//		return;
//	}
//	for (int i = 0; i < k; i++)
//	{
//		fscanf(fout, "%d", &a[i]);
//	}
//	for (int i = (k - 2) / 2; i >= 0; i--)
//	{
//		AdjustDown(a, k, i);
//	}
//	int x;
//	while (fscanf(fout, "%d", &x) > 0)
//	{
//		if (x > a[0])
//		{
//			a[0] = x;
//			AdjustDown(a, k, 0);
//		}
//	}
//	printf("最大的前%d个数:", k);
//	for (int i = 0; i < k; i++)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//
//
//int main()
//{
//	//CreateNDate();
//	PrintTopK();
//	return 0;
//}

typedef struct BinTreeNode
{
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	int val;
}BTnode;

BTnode* TreeFind(BTnode* root,int x)
{
	if (root == NULL)
		return NULL;
	if (root->val == x)
		return root;
	BTnode* ret = TreeFind(root->left, x);
	if (ret)
		return ret;
	return TreeFind(root->right, x);
}