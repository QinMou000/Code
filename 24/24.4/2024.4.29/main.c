#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node *next;
    struct Node *random;
};
 
struct Node* copyRandomList(struct Node* head)
{
    struct Node* cur = head;
    while (cur)
    {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = cur->val;
        newnode->next = cur->next;
        cur->next = newnode;
        cur = cur->next->next;
    }
    cur = head;
    while (cur)
    {
        if (cur->random == NULL)
        {
            cur->next->random = NULL;
        }
        else
        {
            cur->next->random = cur->random->next;
        }
        cur = cur->next->next;
    }
    struct Node* tail = NULL;
    struct Node* _head = NULL;
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;
        if (_head == NULL)
        {
            _head = tail = copy;
        }
        else
        {
            tail->next = copy;
            tail = copy;
        }
        cur = next;
    }
    return _head;
}