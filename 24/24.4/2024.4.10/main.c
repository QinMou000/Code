#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//struct ListNode{
//      int val;
//      struct ListNode *next;
//  };
// 
//struct ListNode* reverseList(struct ListNode* head)
//{
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL, n2 = head, n3 = n2->next;
//    while (n2)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if(n3)
//            n3 = n3->next;
//    }
//    return n1;
//}

struct ListNode {
    int val;
    struct ListNode* next;
}; 
typedef struct ListNode LTN;

struct ListNode* removeElements(struct ListNode* head, int val)
{
    while (head != NULL && head->val == val)
        head = head->next;
    LTN* pcur = head;
    LTN* prev = head;
    while (pcur)
    {
        if (pcur->val != val)
        {
            prev = pcur;
            pcur = pcur->next;
        }
        else
        {
            prev->next = pcur->next;
            pcur = pcur->next;
        }
    }
    return head;
}
