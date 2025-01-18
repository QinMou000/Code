#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdbool.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};
 

bool hasCycle(struct ListNode* head)
{
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}

struct ListNode* detectCycle(struct ListNode* head)
{
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while (fast == slow)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	struct ListNode* meet = fast;
	while (meet == head)
	{
		head = head->next;
		meet = meet->next;
	}
	return meet;
}

int main()
{
	return 0;
}