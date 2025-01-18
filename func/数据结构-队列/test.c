#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"


int main()
{
	Queue Q;
	QueueInit(&Q);
	QueuePush(&Q, 1);
	QueuePush(&Q, 2);

	printf("%d\n", QueueBack(&Q));
	printf("%d\n", QueueFront(&Q));

	QueuePush(&Q, 3);
	QueuePush(&Q, 4);
	printf("%d\n",QueueSize(&Q));
	QNode* cur = Q.phead;
	while (cur)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
	QueuePop(&Q);
	QueuePop(&Q);
	cur = Q.phead;
	while (cur)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	QueuePop(&Q);
	Destory(&Q);
	

	return;
}