#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
 };
 

struct ListNode* MallocNode(int x)
{
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = x;
    newnode->next = NULL;
    return newnode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int ret1 = 0;
    int ret2 = 0;
    struct ListNode* cur1 = l1;
    struct ListNode* cur2 = l2;
    while (cur1)
    {
        ret1 = ret1 * 10 + cur1->val;
        cur1 = cur1->next;
    }
    while (cur2)
    {
        ret2 = ret2 * 10 + cur2->val;
        cur2 = cur2->next;
    }
    int ans = ret1 + ret2;
    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));
    phead->val = ans % 10;
    ans = ans / 10;
    struct ListNode* prev = phead;
    while (ans)
    {
        struct ListNode* cur = MallocNode(ans % 10);
        cur->next = NULL;
        prev->next = cur;
        prev = prev->next;
        ans = ans / 10;
    }
    return phead;
}


int main()
{
    struct ListNode* newnode1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode1->val = 2;
    struct ListNode* newnode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode2->val = 4;
    struct ListNode* newnode3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode3->val = 3;
    struct ListNode* newnode4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode4->val = 5;
    struct ListNode* newnode5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode5->val = 6;
    struct ListNode* newnode6 = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode6->val = 4;
    

    newnode1->next = newnode2;
    newnode2->next = newnode3;
    newnode4->next = newnode5;
    newnode5->next = newnode6;
    newnode3->next = NULL;
    newnode6->next = NULL;


    struct ListNode* ans = addTwoNumbers(newnode1, newnode4);

    return 0;
}