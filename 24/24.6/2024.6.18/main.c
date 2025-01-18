#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode* next;
};


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    struct ListNode* prev = head;
    struct ListNode* cur = head;
    int times = n - m;
    if (cur->next == NULL)
        return cur;
    if (cur->next->next == NULL && times == 1)
    {
        struct ListNode* ans = cur->next;
        cur->next->next = prev;
        prev->next = NULL;
        return ans;
    }
    else if(cur->next->next == NULL)
    {
        return head;
    }
    while (m--)
    {
        prev = cur;
        cur = cur->next;
    }
    struct ListNode* last = cur;
    struct ListNode* Next = cur->next;
    while (times--)
    {
        struct ListNode* tmp = Next->next;
        Next->next = cur;
        cur = Next;
        Next = tmp;
    }
    struct ListNode* first = cur;
    prev->next = first;
    last->next = Next;
    return head;
}

int main()
{
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n1->val = 1;
    n2->val = 2;
    n3->val = 3;
    n4->val = 4;
    n5->val = 5;
    reverseBetween(n1, 2, 4);
}