#define _CRT_SECURE_NO_WARNINGS 1

//
//struct ListNode 
//{
//	int val;
//	struct ListNode *next;
//};
//
//int fun(int a, int b)
//{
//	while (a % b != 0)
//	{
//		int c = a % b;
//		a = b;
//		b = c;
//	}
//	return b;
//}
//
//struct ListNode* insertGreatestCommonDivisors(struct ListNode* head)
//{
//	struct ListNode* cur = head;
//	struct ListNode* next = head;
//	while (next)
//	{
//		cur = next;
//		next = next->next;
//		if (next == NULL)
//			break;
//		int ans = fun(cur->val, next->val);
//		struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//		newnode->val = ans;
//		cur->next = newnode;
//		newnode->next = next;
//	}
//	return head;
//}
//
//int main()
//{
//
//	return 0;
//}

#include<iostream>

using namespace std;

int main()
{
	cout << "hello world!" << endl;
}