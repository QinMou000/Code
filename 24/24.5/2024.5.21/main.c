#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//3���Ӽ�������һ���ַ����������е�Сд��ĸȫ��ת���ɴ�д��ĸ��
// Ȼ�������һ�������ļ���test.dat���б��棬�ٴӸ��ļ��ж����ַ�������ʾ������
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

//4�������ѧ����ÿ��ѧ����3�ſεĳɼ����Ӽ����������ݡ�
// ������ѧ�š����������ſεĳɼ����������ƽ���ɼ���
// ���������ƽ���ִ���ڴ����ļ���stud.dat���С�
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


//5����д��������10000�����������
// �����䱣�浽�����ļ�test.txt�С�
// �ٴ��ļ�test.txt�ж�����Щ�������ڴ��У�
// ����������򣬽������Ľ��������ļ�data.txt�С�
//
//void CreateNDate()
//{
//	// ������
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
//	while (child < size)//���ﲻ����up���ֶ�д��һ��
//	{
//		if (a[child] > a[child + 1] && child + 1 < size)//&&����Ķ�������Ҫ������
//			child++;
//		if (a[parent] > a[child])//child�仯֮�����жϡ�
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
//	printf("����ǰ%d����:", k);
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