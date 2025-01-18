#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct ScoreNode
{
	float data;
	struct ScoreNode* next;
}SCN;

SCN* BuyNode(float x)
{
	SCN* newnode = (SCN*)malloc(sizeof(SCN));
	if (newnode == NULL)
	{
		perror("malloc is fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void SCNPush(SCN** pphead,float x)
{
	SCN* newnode = BuyNode(x);
    if (*pphead == NULL)
    {
        *pphead = newnode;
    }
    else
    {	
        newnode->next = *pphead;
	    *pphead = newnode;
    }

}

void SCNprint(SCN* phead)
{
	SCN* cur = phead;
	while (cur)
	{
		printf("%f ", cur->data);
		cur = cur->next;
	}
}

void Exchange(SCN* x, SCN* y)
{
    float tmp;
    tmp= x->data;
    x->data = y->data;
    y->data = tmp;
}

void SCNsort(SCN* phead)
{
    SCN* cur = NULL;
    SCN* des = phead;
    while (des)
    {
        cur = des->next;
        while (cur)
        {
            if (des->data > cur->data)
            {
                Exchange(des, cur);
            }
            cur = cur->next;
        }
        des = des->next;
    }
}

int main()
{
    SCN* phead = NULL;
    int i = 0;
    while (i++ != 6)
    {
        float x;
        printf("第%d个学生的成绩：",i);
        scanf("%f", &x);
        SCNPush(&phead, x);
    }
    SCNsort(phead);
    printf("它们的成绩排序为：");
	SCNprint(phead);
    printf("\n\n\n");
    printf("12312060216_汪钦：博客链接：https://blog.csdn.net/2301_80194476?type=blog，码云链接：https://gitee.com/wang-qin928");
    printf("\n\n\n");
}